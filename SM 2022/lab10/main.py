import cv2
import numpy as np
import tests as tst
import measurequalities as mq
import readandplotdata as rapd
import pandas as pd

def stats(original, modified, im_num, testsubject):
    mse = mq.MSE(original, modified)
    nmse = mq.NMSE(original, modified)
    psnr = mq.PSNR(original, modified)
    IF = mq.IF(original, modified)
    ssim = mq.SSIM(original, modified)
    print("MSE " + str(testsubject) + " for img " + str(im_num) + " " + str(mse))
    print("NMSE " + str(testsubject) + " for img " + str(im_num) + " " + str(nmse))
    print("PSNR " + str(testsubject) + " for img " + str(im_num) + " " + str(psnr))
    print("IF " + str(testsubject) + " for img " + str(im_num) + " " + str(IF))
    print("SSIM " + str(testsubject) + " for img " + str(im_num) + " " + str(ssim))
    print("######################################################")

    return mse, nmse, psnr, IF, ssim

if __name__ == "__main__":
    img1 = cv2.imread('img1.jpg')
    img2 = cv2.imread('img2.jpg')
    img3 = cv2.imread('img3.jpg')

    # Konwersja na skale szarosci
    img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
    img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
    img3 = cv2.cvtColor(img3, cv2.COLOR_BGR2GRAY)

    cv2.imwrite("img1.jpg", img1)
    cv2.imwrite("img2.jpg", img2)
    cv2.imwrite("img3.jpg", img3)

    #Testowanie dla kompresji stratnej JPEG

    mse_JPEG, nmse_JPEG, psnr_JPEG, IF_JPEG, ssim_JPEG = np.zeros(10), np.zeros(10), np.zeros(10), np.zeros(10), np.zeros(10)

    im_num = 0
    for perc in range(5, 55, 5):
        img_tmp = tst.JPEGTest(img1, perc, im_num)
        img_tmp = cv2.cvtColor(img_tmp, cv2.COLOR_BGR2GRAY)
        mse, nmse, psnr, IF, ssim = stats(img1, img_tmp, im_num, "JPEG")
        mse_JPEG[im_num], nmse_JPEG[im_num], psnr_JPEG[im_num], IF_JPEG[im_num], ssim_JPEG[im_num] = mse, nmse, psnr, IF, ssim
        im_num += 1

    # Testowanie dla rozmycia

    mse_blur, nmse_blur, psnr_blur, IF_blur, ssim_blur = np.zeros(10), np.zeros(10), np.zeros(10), np.zeros(10), np.zeros(10)

    im_num = 0
    for perc in range(2, 12, 1):
        img_tmp = tst.blurTest(img2, perc, im_num)
        mse, nmse, psnr, IF, ssim = stats(img2, img_tmp, im_num, "blur")
        mse_blur[im_num], nmse_blur[im_num], psnr_blur[im_num], IF_blur[im_num], ssim_blur[im_num] = mse, nmse, psnr, IF, ssim
        im_num += 1

    # Testowanie dla zaszumienia

    mse_noise, nmse_noise, psnr_noise, IF_noise, ssim_noise = np.zeros(10), np.zeros(10), np.zeros(10), np.zeros(10), np.zeros(10)

    im_num = 0
    for perc in np.arange(1, 4.8, 0.4):
        img_tmp = tst.noiseTest(img3, perc, im_num)
        mse, nmse, psnr, IF, ssim = stats(img3, img_tmp, im_num, "noise")
        mse_noise[im_num], nmse_noise[im_num], psnr_noise[im_num], IF_noise[im_num], ssim_noise[im_num] = mse, nmse, psnr, IF, ssim
        im_num += 1

    df_JPEG = pd.read_excel('badania_podsumowania/podsumowanie_jpeg.xlsx')
    df_blur = pd.read_excel('badania_podsumowania/podsumowanie_blur.xlsx')
    df_noise = pd.read_excel('badania_podsumowania/podsumowanie_noise.xlsx')
    rapd.plotIDMOS(df_JPEG, "JPEG")
    rapd.plotIDMOS(df_blur, "blur")
    rapd.plotIDMOS(df_noise, "noise")

    measures_labels = ["mse", "nmse", "psnr", "IF", "ssim"]
    measures_JPEG = [mse_JPEG, nmse_JPEG, psnr_JPEG, IF_JPEG, ssim_JPEG]
    measures_blur = [mse_blur, nmse_blur, psnr_blur, IF_blur, ssim_blur]
    measures_noise = [mse_noise, nmse_noise, psnr_noise, IF_noise, ssim_noise]

    for i in range(len(measures_labels)):
        rapd.plotMeasureMOS(df_JPEG, measures_JPEG[i], measures_labels[i], "JPEG", i)

    for i in range(len(measures_labels)):
        rapd.plotMeasureMOS(df_blur, measures_blur[i], measures_labels[i], "blur", i)

    for i in range(len(measures_labels)):
        rapd.plotMeasureMOS(df_noise, measures_noise[i], measures_labels[i], "noise", i)

    rapd.plotCorrelationMOS(df_JPEG, measures_JPEG, "JPEG")
    rapd.plotCorrelationMOS(df_blur, measures_blur, "blur")
    rapd.plotCorrelationMOS(df_noise, measures_noise, "noise")
