import measurequalities as mq
import matplotlib.pyplot as plt
import cv2
import steganography as st
import numpy as np

st = st.Steganography()

def checkQualities(img_orig, img_modified, testsubject):
    mse = mq.MSE(img_orig, img_modified)
    nmse = mq.NMSE(img_orig, img_modified)
    psnr = mq.PSNR(img_orig, img_modified)
    IF = mq.IF(img_orig, img_modified)
    ssim = mq.SSIM(img_orig, img_modified)
    print("MSE " + str(testsubject) + " " + str(mse))
    print("NMSE " + str(testsubject) + " " + str(nmse))
    print("PSNR " + str(testsubject) + " " + str(psnr))
    print("IF " + str(testsubject) + " " + str(IF))
    print("SSIM " + str(testsubject) + " " + str(ssim))
    print("######################################################")


def waterMarkTests(img_orig, img_watermark, alpha):
    # Konwersja obrazka do odcieni szarości w celu ucięcia trzeciego wymiaru
    img_watermark = cv2.cvtColor(img_watermark, cv2.COLOR_RGB2GRAY)
    # print(img_watermark.shape)
    # print(img_watermark)

    # Zapis obrazka w odcieni szarości w celu weryfikacji
    cv2.imwrite("images/watermark_tests/out_img_grayscale_alpha_" + str(alpha) + ".jpg", img_watermark)

    # Progowanie na konkretne wartości w celu binaryzacji obrazu - czarny/biały
    img_watermark = cv2.threshold(img_watermark, 127, 255, cv2.THRESH_BINARY)
    cv2.imwrite("images/watermark_tests/out_img_bool_alpha_" + str(alpha) + ".jpg", img_watermark[1])

    # Konwersja całości obrazu do typu bool
    img_watermark = img_watermark[1].astype(bool)
    # print(img_yin)

    # Przekazanie zbinaryzowanego obrazu do funkcji nakładającej znak wodny

    out = st.water_mark(img_orig, img_watermark, alpha=alpha)
    cv2.imwrite("images/watermark_tests/out_img_alpha_" + str(alpha) + ".jpg", cv2.cvtColor(out, cv2.COLOR_RGB2BGR))


    plt.subplot(1, 3, 1)
    plt.title("Oryginalny obraz ")
    plt.imshow(img_orig)

    plt.subplot(1, 3, 2)
    plt.title("Obraz ze znakiem wodnym, alpha = " + str(alpha))
    plt.imshow(out)

    plt.subplot(1, 3, 3)
    plt.title("Znak wodny nałożony na obraz oryginalny")
    plt.imshow(img_watermark)

    plt.show()

    img_orig = cv2.cvtColor(img_orig, cv2.COLOR_RGB2GRAY)
    out = cv2.cvtColor(out, cv2.COLOR_RGB2GRAY)
    checkQualities(img_orig, out, "watermark")


def steganographyTestsImage(img_orig, data_img, bits, layer="r"):
    data_to_encode = cv2.cvtColor(data_img, cv2.COLOR_RGB2GRAY)

    cv2.imwrite("images/steganography_tests/out_img_grayscale.jpg", data_to_encode)

    data_to_encode = cv2.threshold(data_to_encode, 127, 255, cv2.THRESH_BINARY)
    cv2.imwrite("images/steganography_tests/out_img_bool.jpg", data_to_encode[1])

    data_to_encode = data_to_encode[1].astype(bool)

    if layer == "r":
        img_orig_layer = img_orig[:, :, 0]
    elif layer == "g":
        img_orig_layer = img_orig[:, :, 1]
    else:
        img_orig_layer = img_orig[:, :, 2]

    encoded_img = st.put_data(img_orig_layer, data_to_encode, binary_mask=np.uint8(bits))

    return img_orig_layer, encoded_img

def steganographyTestsText(img_orig, data, bits, layer="r"):

    if layer == "r":
        img_orig_layer = img_orig[:, :, 2]
    elif layer == "g":
        img_orig_layer = img_orig[:, :, 1]
    else:
        img_orig_layer = img_orig[:, :, 0]

    encoded_img = st.put_data(img_orig_layer, data, binary_mask=np.uint8(bits))
    plt.imshow(encoded_img)
    popped_data = st.pop_data(encoded_img, binary_mask=np.uint8(bits), out_shape=data.shape)

    plt.subplot(1, 2, 1)
    plt.title("Oryginalna warstwa obrazu - warstwa " + layer)
    plt.imshow(img_orig_layer, cmap="gray")

    plt.subplot(1, 2, 2)
    plt.title("Zakodowana warstwa obrazu plikiem tekstowym na\nbinary_mask=" + str(bits))
    plt.imshow(encoded_img, cmap="gray")

    plt.show()

    print(popped_data)

    checkQualities(img_orig_layer, encoded_img, "Steganography Text")


def steganographyPlotLayer(img_orig_layer, encoded_img, layer, bits):
    popped_img = st.pop_data(encoded_img, binary_mask=np.uint8(bits))

    cv2.imwrite("images/steganography_tests/img_raw_layer_" + str(layer) + "_" + str(bits) + "bits.jpg",
                img_orig_layer)
    cv2.imwrite("images/steganography_tests/encoded_img_layer_" + str(layer) + "_" + str(bits) + "bits.jpg",
                encoded_img)

    popped_img = cv2.threshold(popped_img, 1, 255, cv2.THRESH_BINARY)
    #cv2.imwrite("images/steganography_tests/popped_img_layer_" + str(layer) + "_" + str(bits) + "bits.jpg", popped_img[1])

    plt.subplot(1, 3, 1)
    plt.title("Oryginalna warstwa obrazu - warstwa " + layer)
    plt.imshow(img_orig_layer, cmap="gray")

    plt.subplot(1, 3, 2)
    plt.title("Zakodowana warstwa obrazu na\nbinary_mask = " + str(bits))
    plt.imshow(encoded_img, cmap="gray")

    plt.subplot(1, 3, 3)
    plt.title("Zdekodowana informacja z warstwy obrazu")
    plt.imshow(popped_img[1], cmap="gray")

    plt.show()

    checkQualities(img_orig_layer, encoded_img, "Steganography Image")


def steganographyAppendAndPlotLayers(orig_image, encoded_img, r, g, b, bits_r, bits_g, bits_b):
    rgb_encoded_image = np.dstack((r, g, b))

    plt.subplot(1, 3, 1)
    plt.title("Oryginalny obraz")
    plt.imshow(orig_image)

    plt.subplot(1, 3, 2)
    plt.title("Zakodowany obraz na\nbinary_mask r = " + str(bits_r) + "\nbinary_mask g = " + str(bits_g) +
              "\nbinary_mask b = " + str(bits_b))
    plt.imshow(rgb_encoded_image)

    plt.subplot(1, 3, 3)
    plt.title("Zakodowana informacja w obrazie")
    plt.imshow(encoded_img)

    plt.show()

    orig_image = cv2.cvtColor(orig_image, cv2.COLOR_RGB2GRAY)
    rgb_encoded_image = cv2.cvtColor(rgb_encoded_image, cv2.COLOR_RGB2GRAY)
    checkQualities(orig_image, rgb_encoded_image, "Steganography RGB Image")