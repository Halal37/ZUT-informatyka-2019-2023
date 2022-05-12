#lw46577 221A 
import sounddevice as sd
import soundfile as sf
import matplotlib.pyplot as plot
import numpy as np
import scipy.fftpack



def norm(vector,mini,maxi):
    min_s = min(vector)
    max_s = max(vector)
    norm = [(vector[i] - min_s)/(max_s - min_s) for i in range(len(vector))]
    return norm
# 1.2 Wczytanie pliku audio
s, fs = sf.read('.//audio.wav', dtype='float32')


# 1.3 Wyswietlenie sygnalu na osi, w przedziale wartosci [-1;1](automatycznie audacity tak nagrywalo)
t=[]
for i in range(len(s)):
    t.append((i/fs)*1000)

plot.plot(t,s[:,0])
plot.show()

#2.1 Podzielenie sygnalu na ramki, a takze uzyskanie funkcji energi E i funkcji przejsc przez zero Z
frame = 0
for i in range(len(t)):
    if t[i]  < 10:
        frame +=1
    else:
        break
frames = int(len(s[:,0])/frame)

E_list = []

frame_s = frame

for i in range(frames):
    E = 0
    for j in range(frame_s-frame,frame_s):
        E += s[j,0]**2
    E_list.append(E)
    frame_s += frame


Z_list = []

frame_s = frame
for i in range(frames):
    Z = 0
    for j in range(frame_s-frame,frame_s-1):
        if s[j,0]*s[j+1,0] < 0:
            Z+=1
        else:
            Z+=0
    Z_list.append(Z)
    frame_s += frame
#2.2 Normalizacja funkcji E i Z, a takze wyswietlenie efektow dzialania w ramach konwencji z konspektu
end_E = norm(E_list,0,1)
t_E = np.linspace(0,max(t),len(end_E))
end_Z = norm(Z_list,0,1)

plot.plot(t,s[:,0],c='g')
plot.plot(t_E,end_E,c='r')
plot.plot(t_E,end_Z,c='b')
plot.title('Signal')
plot.show()

#2.3
#Maksima obu funkcji zblizone są do maksimow dzwieku, minima sa bliskie zeru. Funckje energi E mozna by wykorzystac do podzialu dzwieku na fragmenty dzwieczne i bezdzwieczne 
#2.4
#Przy wiekszych czasowo ramkach wykres funkcji jest czytelniejszy, srednie wartosci tez sa mniejszcze dla wiekszych ramek. Wykresy pokrywaja podobne obszary niezaleznie od ramki. 
#2.5
#Maski wygladaja jak 2 linie proste, funckja E maleje od 1 do 0, funkcja Z rosnie od 0 do 1
#3.1 Lokalizacja samogloski
vocal = []
time = []
for i in range(len(t)):
    if t[i] > 420:
        vocal.append(s[i,0])
        time.append(t[i])
        if len(vocal) == 2048:
            break

plot.plot(time,vocal,c='g')
plot.title('Signal (analysed window) W')
plot.show()
#3.2 Maskowanie sygnalu oknem Hamminga
res_h = np.hamming(len(vocal))

plot.plot(res_h)
plot.title('Hamming window H')
plot.show()
#3.3  Obliczenie fft widma ampitudowego
res_a = [vocal[i] * res_h[i] for i in range(len(res_h))]

plot.plot(res_a)
plot.title('W * H')
plot.show()

transform = scipy.fftpack.fft(res_a)
#3.4 Wyswietlenie wykresu w czestotliwosci w zakresie od 0 do 10000 Hz
amp = [np.log10(abs(transform[i])) for i in range(len(transform))]

s = [i * (fs/len(transform)) for i in range(len(transform))]

plot.plot(s,amp,c='r')
plot.title('Amplitude spectrum')
plot.show()

plot.plot(s,amp,c='r')
plot.xlim([0,10000])
plot.title('Amplitude spectrum: log(abs(fft(W*H)))')
plot.show()
#3.5 W moim przypadku F0 wynosi 18
F0=np.argmax(amp)
print("Takie maksy ",F0)
#3.6 
#Widma samoglowsek zmieniaja sie miedzy soba, bezdzwieczne maja znacznie nizsze F0, zmienia sie tez dla poszczegolnych glosek.
import librosa

#4.1 Kopiowanie samogloski do zmiennej okno
okno = np.array(vocal)
#4.2 Wyznaczenie wspolczynnikow liniowego filtra LPC
p = 20
a = librosa.lpc(okno,p)

#4.3
# Jest to kodowanie oparte na predykcji liniowej. Stosowana jest do przetwarzania sygnalow audio, a w szczegolnosci mowy ludzkiej. Jest to jedna lepszych metod przetwarzania mowy. 
#4.4 Uzupelnienie listy a zerami 
a = list(a)
for _ in range(2048-len(a)):
    a.append(0)

#4.5 Wyswietlanie efektow dzialania, a takze wygladzenie widma amplitudowego 
fft_out = np.fft.fft(a)
LPC = [np.log10(abs(fft_out[i])) for i in range(len(fft_out))]



s = [i * (fs/len(LPC)) for i in range(len(LPC))]


LPC = np.array(LPC)
LPC = -1 * LPC

plot.plot(s,fft_out,c='b')
plot.plot(s,LPC,c='r')
plot.show()