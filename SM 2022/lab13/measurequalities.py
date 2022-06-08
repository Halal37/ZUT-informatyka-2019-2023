import numpy as np
import skimage

def MSE(source, modified):
    # modified = K
    # source = I

    m = source.shape[0]
    n = source.shape[1]

    result = 0
    for i in range(m):
        for j in range(n):
            result += (int(source[i][j]) - int(modified[i][j])) ** 2

    return (1 / (m * n)) * result


def NMSE(source, modified):
    # modified = K
    # source = I

    m = source.shape[0]
    n = source.shape[1]

    mse = MSE(source, modified)

    result = 0
    for i in range(m):
        for j in range(n):
            result += int(modified[i][j]) ** 2

    result = (1 / (m * n)) * result

    return mse / result


def PSNR(source, modified):
    # modified = K
    # source = I

    return 10 * np.log10(np.max(source) ** 2 / MSE(source, modified))


def IF(source, modified):
    # modified = K
    # source = I

    m = source.shape[0]
    n = source.shape[1]

    result = 0
    for i in range(m):
        for j in range(n):
            result += (int(modified[i][j]) - int(source[i][j]))**2

    tmp = result
    result = 0
    for i in range(m):
        for j in range(n):
            result += int(modified[i][j]) * int(source[i][j])

    return 1 - tmp/result


def SSIM(source, modified):
    return skimage.metrics.structural_similarity(source, modified)
