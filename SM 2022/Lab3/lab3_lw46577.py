from operator import mod
import cv2
import matplotlib.pyplot as plt
import numpy as np
import math
import sys
from sklearn.preprocessing import scale

#Metoda interpolacji dwuliniowej
def bilinear(img: np.ndarray, scale: float):
	old_h, old_w, c = img.shape
	new_h: int = int(old_h * scale)
	new_w: int = int(old_w * scale)
	resized = np.zeros((new_h, new_w, c))

	w_scale_factor: float = (old_w) / (new_w) 
	h_scale_factor: float = (old_h) / (new_h)
	for i in range(new_h):
		for j in range(new_w):

			x: float = i * h_scale_factor
			y: float = j * w_scale_factor

			x_floor: int = math.floor(x)
			x_ceil: int = min(old_h - 1, math.ceil(x))
			y_floor: int = math.floor(y)
			y_ceil: int = min(old_w - 1, math.ceil(y))

			if (x_ceil == x_floor) and (y_ceil == y_floor):
				q = img[int(x), int(y), :]
			elif (x_ceil == x_floor):
				q1 = img[int(x), int(y_floor), :]
				q2 = img[int(x), int(y_ceil), :]
				q = q1 * (y_ceil - y) + q2 * (y - y_floor)
			elif (y_ceil == y_floor):
				q1 = img[int(x_floor), int(y), :]
				q2 = img[int(x_ceil), int(y), :]
				q = (q1 * (x_ceil - x)) + (q2	 * (x - x_floor))
			else:
				v1 = img[x_floor, y_floor, :]
				v2 = img[x_ceil, y_floor, :]
				v3 = img[x_floor, y_ceil, :]
				v4 = img[x_ceil, y_ceil, :]

				q1 = v1 * (x_ceil - x) + v2 * (x - x_floor)
				q2 = v3 * (x_ceil - x) + v4 * (x - x_floor)
				q = q1 * (y_ceil - y) + q2 * (y - y_floor)

			resized[i,j,:] = q
	resized = resized.astype(np.uint8)
	plt.imshow(resized)
	plt.show()
	edges1 = cv2.Canny(img,100,200)
	edges2 = cv2.Canny(resized,100,200)
	edges1 = cv2.Canny(img,100,100)
	edges2 = cv2.Canny(resized,100,100)
	plt.subplot(121),plt.imshow(edges1, cmap = 'gray')
	plt.subplot(122), plt.imshow(edges2, cmap = 'gray')
	plt.show()

#Metoda najbliższego sąsiada
def nearestNeighborScaling(img, scale):
	img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
	old_h, old_w, c = img.shape

	new_w = int(old_w * scale)
	new_h = int(old_h * scale)

	resized = np.empty((new_w, new_h, c), dtype = np.uint8)
	for i in range(new_w-1):
		for j in range(new_h-1):
			p_x=int(i / scale)
			p_y=int(j / scale)
	
			resized[i + 1, j + 1]=img[1 + p_x,1 + p_y]
	
	plt.imshow(resized)
	plt.show()
	edges1 = cv2.Canny(img,100,100)
	edges2 = cv2.Canny(resized,100,100)
	plt.subplot(121),plt.imshow(edges1, cmap = 'gray')
	plt.subplot(122), plt.imshow(edges2, cmap = 'gray')
	plt.show()
	
#Przez porblemy z implementacją pozostale obrazy sa skalowane w skali szarosci	
#Algorytm zmniejszania obrazu przy uzyciu sredniej
def downScaleMean(img: np.ndarray, scale: float): 
	resultingWidth: int = math.ceil(img.shape[0] * scale)
	resultingHeight: int = math.ceil(img.shape[1] * scale)
	blockHeight: int = math.ceil(img.shape[0] / resultingWidth)
	blockWidth: int = math.ceil(img.shape[1] / resultingHeight)
	resized = np.zeros((resultingWidth, resultingHeight))

	startingRow = 0
	startingCol = 0
	endingRow = blockHeight
	endingCol = blockWidth
	func = np.mean

	
	for row in range(resultingHeight):
		for col in range(resultingWidth):
			resized[row, col] = func(img[startingRow:endingRow, startingCol:endingCol])
			startingCol = endingCol + 1
			endingCol = endingCol + blockWidth
		startingRow = endingRow + 1
		endingRow = endingRow + blockHeight
		startingCol = 0
		endingCol = blockWidth
			
	resized = resized.astype(np.uint8)
	plt.imshow(resized)
	plt.show()
	edges1 = cv2.Canny(img,100,100)
	edges2 = cv2.Canny(resized,100,100)
	plt.subplot(121),plt.imshow(edges1, cmap = 'gray')
	plt.subplot(122), plt.imshow(edges2, cmap = 'gray')
	plt.show()

#Algorytm zmniejszania obrazu przy uzyciu mediany
def downScaleMedian(img: np.ndarray, scale: float): 
	resultingWidth: int = math.ceil(img.shape[0] * scale)
	resultingHeight: int = math.ceil(img.shape[1] * scale)
	blockHeight: int = math.ceil(img.shape[0] / resultingWidth)
	blockWidth: int = math.ceil(img.shape[1] / resultingHeight)
	resized = np.zeros((resultingWidth, resultingHeight))

	startingRow = 0
	startingCol = 0
	endingRow = blockHeight
	endingCol = blockWidth
	func = np.median
	
	for row in range(resultingHeight):
		for col in range(resultingWidth):
			resized[row, col] = func(img[startingRow:endingRow, startingCol:endingCol])
			startingCol = endingCol + 1
			endingCol = endingCol + blockWidth
		startingRow = endingRow + 1
		endingRow = endingRow + blockHeight
		startingCol = 0
		endingCol = blockWidth
			
	resized = resized.astype(np.uint8)
	plt.imshow(resized)
	plt.show()
	edges1 = cv2.Canny(img,100,100)
	edges2 = cv2.Canny(resized,100,100)
	plt.subplot(121),plt.imshow(edges1, cmap = 'gray')
	plt.subplot(122), plt.imshow(edges2, cmap = 'gray')
	plt.show()	

#Algorytm zmniejszania obrazu przy uzyciu sredniej wazonej
def downScaleWeightedMean(img, scale):
	resultingWidth: int = math.ceil(img.shape[0] * scale)
	resultingHeight: int = math.ceil(img.shape[1] * scale)
	blockHeight: int = math.ceil(img.shape[0] / resultingWidth)
	blockWidth: int = math.ceil(img.shape[1] / resultingHeight)
	res = np.zeros((resultingWidth, resultingHeight))
	startingRow = 0
	startingCol = 0
	endingRow = blockHeight 
	endingCol = blockWidth 
	centerWeight = np.ceil(blockWidth / 2)
	padAmount = int(np.floor(blockWidth / 2))
	weights = np.array([[centerWeight]])
	weights = np.pad(weights, pad_width=padAmount, mode="linear_ramp", end_values=1)


	for row in range(resultingHeight):
		for col in range(resultingWidth):
			multiplied = np.multiply(weights, img[startingRow:endingRow, startingCol:endingCol])
			blockSum = np.sum(multiplied)
			weightedSum = blockSum / np.sum(weights)
			res[row, col] = weightedSum
			startingCol = endingCol
			endingCol = endingCol + blockWidth
		startingRow = endingRow	
		endingRow = endingRow + blockHeight
		startingCol = 0
		endingCol = blockWidth
	
	resized = res.astype(np.uint8)
	plt.imshow(resized)
	plt.show()
	edges1 = cv2.Canny(img,100,100)
	edges2 = cv2.Canny(res,100,100)
	plt.subplot(121),plt.imshow(edges1, cmap = 'gray')
	plt.subplot(122), plt.imshow(edges2, cmap = 'gray')
	plt.show()


if __name__ == '__main__':
	np.set_printoptions(threshold=sys.maxsize)
	img = cv2.imread("C:/Users/JaSzw/Downloads/Bla/cat.jpg")
	imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	img2 = cv2.imread("C:/Users/JaSzw/Downloads/Bla/kal.png")
	img2Gray = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
	img3 = cv2.imread("C:/Users/JaSzw/Downloads/Bla/tra.jpg")
	img3Gray = cv2.cvtColor(img3, cv2.COLOR_BGR2GRAY)
	downScaleMean(imgGray, 0.2)
	#downScaleMedian(imgGray, 0.2)
#	bilinear(img,0.2)
	#nearestNeighborScaling(img,0.2)
#	downScaleWeightedMean(imgGray, 0.2)
	downScaleMean(img2Gray, 0.2)
#	downScaleMedian(img2Gray, 0.2)
#	bilinear(img2,0.2)
	#nearestNeighborScaling(img2,0.2)
#	downScaleWeightedMean(img2Gray, 0.2)	
	downScaleMean(img3Gray, 0.2)
#	downScaleMedian(img3Gray, 0.2)
#	bilinear(img3,0.2)
	#nearestNeighborScaling(img3,0.2)
#	downScaleWeightedMean(img3Gray, 0.2)



	
	
	