import cv2
import numpy as np


# Funkcja testująca dla JPEG
def JPEGTest(img, perc, imnum):
    encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), perc]
    result, encimg = cv2.imencode('.jpg', img, encode_param)
    decimg = cv2.imdecode(encimg, 1)

    cv2.imwrite("images/jpeg/outimg_jpeg" + str(imnum) + ".png", decimg)
    return decimg


# Funkcja testująca dla rozmycia
def blurTest(img, perc, imnum):
    blur = cv2.blur(img, (perc, perc))
    # gaussblur = cv2.GaussianBlur(img, (perc, perc), 0)
    # median = cv2.medianBlur(img, perc)
    # bilateralblur = cv2.bilateralFilter(img, perc, 75, 75)

    cv2.imwrite("images/blur/outimg_blur" + str(imnum) + ".png", blur)
    return blur


# Funkcja testująca dla szumu
def noiseTest(img, alpha, imnum):
    rand = 25 * np.random.random(img.shape)
    noisy = (img + alpha * rand).clip(0, 255).astype(np.uint8)

    cv2.imwrite("images/noise/outimg_noise" + str(imnum) + ".png", noisy)
    return noisy
