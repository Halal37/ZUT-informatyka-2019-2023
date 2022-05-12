#Wojciech Lidwin 221A lw46577
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from PIL import Image
import cv2

def dyskretyzacja_sin(fs,f):
    t=np.arange(0,1,1/fs)
    s=np.sin(2*np.pi*f*t)
    plt.plot(t,s)
    plt.show()
    return t,s

dyskretyzacja_sin(20,10)

dyskretyzacja_sin(21,10)

dyskretyzacja_sin(30,10)

dyskretyzacja_sin(45,10)

dyskretyzacja_sin(50,10)

dyskretyzacja_sin(100,10)

dyskretyzacja_sin(150,10)

dyskretyzacja_sin(250,10)

dyskretyzacja_sin(1000,10)

#Czy istnieje twierdzenie, które określa z jaką częstotliwością należy próbkować, aby móc wiernie odtworzyć sygnał? Jak się nazywa?
#twierdzenie Nyquista–Shannona

#Jak nazywa się zjawisko, które z powodu błędnie dobranej częstotliwości próbkowania powoduje błędną interpretację sygnału?
#Aliasing

#3.1
img=mpimg.imread(".\\rekin.png")

#3.2
print(np.shape(img))
print()
#RGB

#3.3
img_2=Image.open(".\\rekin.png")
print(img_2.mode)
print()

#3.4
#1 wartosc
zdjecie1=img.mean(axis=-1,keepdims=1)


#2 luminancja
r,g,b=img[:,:,0], img[:,:,1], img[:,:,2]
zdjecie2=0.2126 * r + 0.7152 * g + 0.0722 * b

#3 jasność
zdjecie3=(np.max(img,axis=-1,keepdims=1) + np.min(img,axis=-1,keepdims=1))/2 


#3.5
print(np.histogram(zdjecie1))
#(array([237653, 249971, 121755,  57029,  33811,  20348,  17654,  18505,
#        24808,  28466], dtype=int64), array([0.01045752, 0.10941177, 0.208366  , 0.30732027, 0.4062745 ,
#       0.50522876, 0.604183  , 0.7031373 , 0.8020915 , 0.90104574,
#       1.        ], dtype=float32))
print()

print(np.histogram(zdjecie2))
#(array([336786, 199951,  90441,  50237,  28425,  17655,  15854,  16989,
#        21968,  31694], dtype=int64), array([0.0022651 , 0.10203859, 0.20181207, 0.30158556, 0.40135905,
#       0.50113255, 0.600906  , 0.70067954, 0.800453  , 0.90022653,
#       1.        ], dtype=float32))
print()

print(np.histogram(zdjecie3))
#(array([191098, 280128, 137755,  59286,  34887,  21535,  17630,  19190,
#        23201,  25290], dtype=int64), array([0.01568628, 0.11411764, 0.21254902, 0.31098038, 0.40941176,
#       0.50784314, 0.6062745 , 0.7047059 , 0.80313724, 0.90156865,
#       1.        ], dtype=float32))
print()


#3.6
print(np.histogram(zdjecie3,bins=16))
#(array([ 56652, 214009, 172604, 113100,  61857,  38647,  27115,  19170,
#        14299,  11663,  11160,  11137,  12756,  15041,  14699,  16091],
#      dtype=int64), array([0.01568628, 0.07720588, 0.13872549, 0.2002451 , 0.2617647 ,
#       0.32328433, 0.38480392, 0.44632354, 0.50784314, 0.56936276,
#       0.6308824 , 0.69240195, 0.75392157, 0.8154412 , 0.8769608 ,
#       0.9384804 , 1.        ], dtype=float32))
print()

#3.7
mediana=np.median(np.histogram(zdjecie3)[0])
print(np.histogram(zdjecie3,bins=int(mediana)))
#(array([ 1,  0,  0, ...,  0,  0, 21], dtype=int64), array([0.01568628, 0.01571899, 0.0157517 , ..., 0.99993455, 0.9999673 ,
#       1.        ], dtype=float32))
print()

#3.8
plt.imshow(img)
plt.title("Oryginalny obraz")
plt.show()

plt.imshow(zdjecie1)
plt.title("Usrednienie wartosci piksela")
plt.show()

plt.imshow(zdjecie2)
plt.title("Wyznaczenie luminancji piksela")
plt.show()

plt.imshow(zdjecie3)
plt.title("Wyznaczenie jasnosci piksela")
plt.show()

plt.hist(np.histogram(zdjecie1))
plt.title("Histogram dla: Usrednienie wartosci piksela")
plt.show()

plt.hist(np.histogram(zdjecie2))
plt.title("Histogram dla: Wyznaczenie luminancji piksela")
plt.show()

plt.hist(np.histogram(zdjecie3))
plt.title("Histogram dla: Wyznaczenie jasnosci piksela")
plt.show()

plt.hist(np.histogram(zdjecie3,bins=16))
plt.title("3.6")
plt.show()

plt.hist(np.histogram(zdjecie3,bins=int(mediana)))
plt.title("3.7")
plt.show()
print()

#Zadanie 4
obraz=cv2.imread(".\\gf-5c49-u1Vi-Fyi6_klan-pawel-lubicz-tomasz-stockinger-320x213.png")


#4.2
zdjecie4=(np.max(obraz,axis=-1,keepdims=1) + np.min(obraz,axis=-1,keepdims=1))/2 
plt.imshow(zdjecie4)
plt.show()
plt.hist(np.histogram(zdjecie4))
plt.show()

#4.3
np.min(plt.hist(np.histogram(zdjecie4))[1])

#4.4
ret,thresh=cv2.threshold(zdjecie4,np.min(plt.hist(np.histogram(zdjecie4))[1]),255,0)
ret,thresh2=cv2.threshold(zdjecie4,np.min(plt.hist(np.histogram(zdjecie4))[1]),255,1)

dla_zero=Image.fromarray(thresh)
dla_zero.show()
dla_jeden=Image.fromarray(thresh2)
dla_jeden.show()

#4.5
zdjecie = cv2.cvtColor(obraz,cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(zdjecie,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
nowy=Image.fromarray(thresh)
nowy.show()

