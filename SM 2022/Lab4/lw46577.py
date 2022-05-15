import numpy as np
import matplotlib.pyplot as plt
from skimage.util import img_as_float


def colorFit(col, palette):
    a = np.linalg.norm(palette - col, axis=1)
    return palette[np.argmin(a)]


def quantize(image, palette):
    outImage = image.copy()
    for row in range(0, image.shape[0]):
        for pixel in range(0, image.shape[1]):
            outImage[row, pixel] = colorFit(image[row, pixel], palette)
    return outImage


def random(image):
    outImage = image.copy()
    r = np.random.rand(image.shape[0], image.shape[1])
    for row in range(0, image.shape[0]):
        for col in range(0, image.shape[1]):
            outImage[row, col] = image[row, col] > r[row, col]
    return outImage


def M2(image, palette):
    outImage = image.copy()
    m2 = np.matrix('0,8,2,10;'
                   '12,4,14,6;'
                   '3,11,1,9;'
                   '15,7,13,5')
    Mpre = 1 / 16 * (m2 + 1) - 0.5
    for row in range(0, image.shape[0]):
        for col in range(0, image.shape[1]):
            outImage[row, col] = colorFit(outImage[row, col] + Mpre[row % 4, col % 4], palette)
    return outImage


def FloydSteinberg(image, palette):
    outImage = image.copy()
    for row in range(1, image.shape[0]-1):
        for col in range(1, image.shape[1]-1):
            oldpixel = outImage[row, col].copy()
            newpixel = colorFit(oldpixel, palette)
            outImage[row, col] = newpixel
            quanterror = oldpixel - newpixel
            outImage[row + 1, col    ] = np.clip(outImage[row + 1, col    ] + quanterror * 7 / 16, 0, 1)
            outImage[row - 1, col + 1] = np.clip(outImage[row - 1, col + 1] + quanterror * 3 / 16, 0, 1)
            outImage[row    , col + 1] = np.clip(outImage[row    , col + 1] + quanterror * 5 / 16, 0, 1)
            outImage[row + 1, col + 1] = np.clip(outImage[row + 1, col + 1] + quanterror * 1 / 16, 0, 1)
    return outImage


def doitall(image, palette):

    cmap = None
    width = 4
    if len(palette) == 2:
            width = 5
            cmap = plt.cm.gray

    ax = plt.subplot(1, width, 1)
    ax.set_axis_off()
    ax.set_title('Oryginalny obraz')
    plt.imshow(image, cmap=cmap)

    ax = plt.subplot(1, width, 2)
    ax.set_axis_off()
    ax.set_title('Kwantyzacja')
    plt.imshow(quantize(image, palette), cmap=cmap)

    ax = plt.subplot(1, width, 3)
    ax.set_axis_off()
    ax.set_title('Dithering zorganizowany')
    plt.imshow(M2(image, palette), cmap=cmap)

    ax = plt.subplot(1, width, 4)
    ax.set_axis_off()
    ax.set_title('Dithering Floyd-Steinberg')
    plt.imshow(FloydSteinberg(image, palette), cmap=cmap)

    if  len(palette) == 2:
        ax = plt.subplot(1, width, 5)
        ax.set_axis_off()
        ax.set_title('Dithering losowy')
        plt.imshow(random(image), cmap=cmap)

    plt.tight_layout()
    plt.show()


image = img_as_float(plt.imread('C:/Users/JaSzw/Downloads/SM_Lab04/SM_Lab04/0008.png'))

image2 = img_as_float(plt.imread('C:/Users/JaSzw/Downloads/SM_Lab04/SM_Lab04/0010.jpg'))

image3 = img_as_float(plt.imread('C:/Users/JaSzw/Downloads/SM_Lab04/SM_Lab04/0009.png'))

image4 = img_as_float(plt.imread('C:/Users/JaSzw/Downloads/SM_Lab04/SM_Lab04/0014.jpg'))

image5 = img_as_float(plt.imread('C:/Users/JaSzw/Downloads/SM_Lab04/SM_Lab04/0013.jpg'))

image6 = img_as_float(plt.imread('C:/Users/JaSzw/Downloads/SM_Lab04/SM_Lab04/0011.jpg'))

greyscalePalette1bit = np.linspace(0, 1, 2).reshape((2, 1))
greyscalePalette2bit = np.linspace(0, 1, 4).reshape((4, 1))
greyscalePalette4bit = np.linspace(0, 1, 8).reshape((8, 1))



colorPalette8bit = np.matrix('0., 0., 0.;'
                              '0., 0., 1.;'
                              '0., 1., 0.;'
                              '0., 1., 1.;'
                              '1., 0., 0.;'
                              '1., 0., 1.;'
                              '1., 1., 0.;'
                              '1., 1., 1.')
colorPalette16bit = np.matrix('0,0,0;'
                               '0,1,1;'
                               '0,0,1;'
                               '1,0,1;'
                               '0,0.5,0;'
                               '0.5,0.5,0.5;'
                               '0,1,0;'
                               '0.5,0,0;'
                               '0,0,0.5;'
                               '0.5,0.5,0;'
                               '0.5,0,0.5;'
                               '1,0,0;'
                               '0.75,0.75,0.75;'
                               '0,0.5,0.5;'
                               '1,1,1;'
                               '1,1,0')

doitall(image, greyscalePalette1bit)
doitall(image, greyscalePalette2bit)
doitall(image, greyscalePalette4bit)
doitall(image2, greyscalePalette1bit)
doitall(image2, greyscalePalette2bit)
doitall(image2, greyscalePalette4bit)
doitall(image3, greyscalePalette1bit)
doitall(image3, greyscalePalette2bit)
doitall(image3, greyscalePalette4bit)

doitall(image4, colorPalette8bit)
doitall(image4, colorPalette16bit)
doitall(image5, colorPalette8bit)
doitall(image5, colorPalette16bit)
doitall(image6, colorPalette8bit)
doitall(image6, colorPalette16bit)

colorPalettespecial = np.matrix('0.820, 0.318, 0.180;'
                                 '0.859, 0.820, 0.780;'
                                 '0.008, 0.016, 0.012;'
                                 '0.349, 0.149, 0.067;'
                                 '0.918, 0.686, 0.192;'
                                 '0.745, 0.247, 0.078;'
                                 '0.212, 0.102, 0.059;'
                                 '0.373, 0.149, 0.082;'
                                 '0.710, 0.235, 0.157;'
                                 '0.851, 0.631, 0.157;'
                                 '0.843, 0.843, 0.647;'
                                 '0.875, 0.506, 0.125;'
                                 '0.918, 0.514, 0.188;'
                                 '0.506, 0.165, 0.098;'
                                 '0.835, 0.333, 0.157;'
                                 '0.812, 0.235, 0.165;'
                                 '0.655, 0.220, 0.141')

ax = plt.subplot(1, 2, 1)
ax.set_axis_off()
ax.set_title('Oryginalny obraz')
plt.imshow(image4)

ax = plt.subplot(1, 2, 2)
ax.set_axis_off()
ax.set_title('Kwantyzacja')
plt.imshow(quantize(image4, colorPalettespecial))

plt.show()