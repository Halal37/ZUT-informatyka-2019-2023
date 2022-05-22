import cv2
import numpy as np
import matplotlib.pyplot as plt

plik = "clip_4.mp4"  
ile = 15  
key_frame_counter = 7 
plot_frames = np.array([30, 45])  
auto_pause_frames = np.array([25])  
subsampling = "4:2:2" 
subsampling_name = "_4_2_2_"
wyswietlaj_klatki = False  
RLE = True
stopien_kompresji = 1
Cb_shape = []
Cr_shape = []


class data:
    def init(self):
        self.Y = None
        self.Cb = None
        self.Cr = None


def coder_rle(input_array):
    output = [input_array[0]]
    lenght = len(input_array)
    counter = 0
    for i in range(1, lenght):
        counter += 1
        if input_array[i] != input_array[i - 1]:
            output.append(counter)
            output.append(input_array[i])
            counter = 0
    output.append(counter + 1)

    return output


def decoder_rle(input_array):
    output = []
    for i in range(0, len(input_array) - 1, 2):
        for j in range(input_array[i + 1]):
            output.append(input_array[i])

    return np.array(output)


def chroma_subsampling(warstwa, subsampling_type):
    output = 0
    if subsampling_type == "4:4:4":
        return warstwa
    elif subsampling_type == "4:2:2":
        output = np.delete(warstwa, list(range(1, warstwa.shape[1], 2)), axis=1)
    elif subsampling_type == "4:1:0":
        output = np.delete(warstwa, list(range(1, warstwa.shape[1], 2)), axis=1)
        output = np.delete(output, list(range(1, output.shape[1], 2)), axis=1)
        output = np.delete(output, list(range(1, warstwa.shape[0], 2)), axis=0)

    return output


def chroma_resampling(warstwa, subsampling_type):
    output = 0
    if subsampling_type == "4:4:4":
        return warstwa
    elif subsampling_type == "4:2:2":
        output = np.repeat(warstwa, 2, axis=1)
    elif subsampling_type == "4:1:0":
        output = np.repeat(warstwa, 2, axis=0)
        output = np.repeat(output, 2, axis=1)
        output = np.repeat(output, 2, axis=1)

    return output


def compress(Y, Cr, Cb, key_frame_Y, key_frame_Cr, key_frame_Cb):
    global Cr_shape
    global Cb_shape
    data.Y = Y
    data.Cr = chroma_subsampling(Cr, subsampling)
    data.Cb = chroma_subsampling(Cb, subsampling)
    data.Y = ((data.Y.astype('int16') - key_frame_Y.astype('int16')) // stopien_kompresji).astype('int8')
    data.Cr = ((data.Cr.astype('int16') - key_frame_Cr.astype('int16')) // stopien_kompresji).astype('int8')
    data.Cb = ((data.Cb.astype('int16') - key_frame_Cb.astype('int16')) // stopien_kompresji).astype('int8')

    if RLE:
        Cb_shape = data.Cb.shape
        Cr_shape = data.Cr.shape

        data.Y = data.Y.flatten()
        data.Cr = data.Cr.flatten()
        data.Cb = data.Cb.flatten()

        data.Y = np.array(coder_rle(data.Y))
        data.Cr = np.array(coder_rle(data.Cr))
        data.Cb = np.array(coder_rle(data.Cb))

    return data


def decompress(data, key_frame_Y, key_frame_Cr, key_frame_Cb):
    if RLE:
        data.Y = decoder_rle(data.Y)
        data.Cr = decoder_rle(data.Cr)
        data.Cb = decoder_rle(data.Cb)

        data.Y = data.Y.reshape(key_frame_Y.shape)
        data.Cr = data.Cr.reshape(Cr_shape)
        data.Cb = data.Cb.reshape(Cb_shape)

    data.Y = (data.Y * stopien_kompresji + key_frame_Y)
    data.Cr = (data.Cr * stopien_kompresji + key_frame_Cr)
    data.Cb = (data.Cb * stopien_kompresji + key_frame_Cb)
    data.Cr = chroma_resampling(data.Cr, subsampling)
    data.Cb = chroma_resampling(data.Cb, subsampling)
    frame = np.dstack([data.Y, data.Cr, data.Cb]).astype(np.uint8)

    return frame


cap = cv2.VideoCapture(plik)

if ile < 0:
    ile = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

cv2.namedWindow('Normal Frame')
cv2.namedWindow('Decompressed Frame')

compression_information = np.zeros((3, ile))

for i in range(ile):
    ret, frame = cap.read()
    if wyswietlaj_klatki:
        cv2.imshow('Normal Frame', frame)
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2YCrCb)
    if (i % key_frame_counter) == 0:  
        cY = frame[:, :, 0].copy()
        cCr = chroma_subsampling(frame[:, :, 1].copy(), subsampling)
        cCb = chroma_subsampling(frame[:, :, 2].copy(), subsampling)

        keyData = data()
        keyData.Y = cY.copy()
        keyData.Cr = cCr.copy()
        keyData.Cb = cCb.copy()

        if RLE:
            tmpY = np.array(coder_rle(cY.copy().flatten()))
            tmpCr = np.array(coder_rle(cCr.copy().flatten()))
            tmpCb = np.array(coder_rle(cCb.copy().flatten()))

            tmpY = decoder_rle(tmpY)
            tmpCr = decoder_rle(tmpCr)
            tmpCb = decoder_rle(tmpCb)

            tmpY = tmpY.reshape(cY.shape)
            tmpCr = tmpCr.reshape(cCr.shape)
            tmpCb = tmpCb.reshape(cCb.shape)

            tmpCr = chroma_resampling(tmpCr, subsampling)
            tmpCb = chroma_resampling(tmpCb, subsampling)

            d_frame = np.dstack([tmpY, tmpCr, tmpCb]).astype(np.uint8)
        else:
            tmpCr = chroma_resampling(cCr.copy(), subsampling)
            tmpCb = chroma_resampling(cCb.copy(), subsampling)
            d_frame = np.dstack([cY, tmpCr, tmpCb]).astype(np.uint8)
    else:  # kompresja
        cdata = compress(frame[:, :, 0].copy(), frame[:, :, 1].copy(), frame[:, :, 2].copy(), keyData.Y, keyData.Cr,
                         keyData.Cb)
        cY = cdata.Y
        cCr = cdata.Cr
        cCb = cdata.Cb
        d_frame = decompress(cdata, keyData.Y, keyData.Cr, keyData.Cb)

    if RLE:
        cY = np.array(cY)
        cCr = np.array(cCr)
        cCb = np.array(cCb)
    compression_information[0, i] = (frame[:, :, 0].size - cY.size) / frame[:, :, 0].size
    compression_information[1, i] = (frame[:, :, 1].size - cCr.size) / frame[:, :, 1].size
    compression_information[2, i] = (frame[:, :, 2].size - cCb.size) / frame[:, :, 2].size
    if wyswietlaj_klatki:
        cv2.imshow('Decompressed Frame', cv2.cvtColor(d_frame, cv2.COLOR_YCrCb2BGR))
    if np.any(plot_frames == i): 
        fig, axs = plt.subplots(1, 3, sharey=True)
        fig.set_size_inches(16, 5)
        axs[0].imshow(cv2.cvtColor(frame, cv2.COLOR_YCrCb2RGB))
        axs[0].title.set_text("Original")
        axs[2].imshow(cv2.cvtColor(d_frame, cv2.COLOR_YCrCb2RGB))
        axs[2].title.set_text("Decompressed")
        diff = frame.astype(float) - d_frame.astype(float)
        print(np.min(diff), np.max(diff))
        axs[1].imshow(diff, vmin=np.min(diff), vmax=np.max(diff))
        axs[1].title.set_text("Differences")

        plt.savefig( "C:/Users/JaSzw/Downloads/kompresja_video/" + plik + subsampling_name + str(
    stopien_kompresji)  + str(RLE) + str(key_frame_counter) + 'chrom.png')
    if np.any(auto_pause_frames == i):
        cv2.waitKey(-1)  

    k = cv2.waitKey(1) & 0xff

    if k == ord('q'):
        break
    elif k == ord('p'):
        cv2.waitKey(-1)  
plt.figure()
plt.plot(np.arange(0, ile), compression_information[0, :] * 100, label='Y')
plt.plot(np.arange(0, ile), compression_information[1, :] * 100, label='Cr')
plt.plot(np.arange(0, ile), compression_information[2, :] * 100, label='Cb')
plt.legend()
plt.title(plik + ", Stopień kompresji: " + str(
    stopien_kompresji) + ",\nStopień redukcji chrominacji: " + subsampling + ",\nRLE: " + str(RLE))
plt.savefig("C:/Users/JaSzw/Downloads/kompresja_video/" + plik + subsampling_name + str(
    stopien_kompresji) +  str(RLE) + str(key_frame_counter) +  'foo.png')
