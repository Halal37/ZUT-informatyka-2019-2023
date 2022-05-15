import numpy as np
import scipy.io.wavfile as wavfile
import matplotlib.pyplot as plt
import cv2

if __name__ == '__main__':
#Czesc video
    cap = cv2.VideoCapture(0) 
    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    out = cv2.VideoWriter('output.avi', fourcc, 20.0, (640,  480))
    out2 = cv2.VideoWriter('output2.avi', fourcc, 20.0, (340,  180))
    if not cap.isOpened():
      print("Cannot open camera")
      exit()
    while True:
      ret, frame = cap.read()
      if not ret:
         print("Can't receive frame (stream end?). Exiting ...")
         break
      flip=cv2.flip(frame,0)
      flipper=flip[300:700,300:720]
      out.write(frame)
      out2.write(flipper)

      cv2.imshow('frame', flip)
      if cv2.waitKey(1) == ord('q'):
         break
      out.release()
      out2.release()

      cap.release()
      cv2.destroyAllWindows()
#Czesc audio
    ECHO_DURATION = 0.25
    DELAY_AMPLITUDE = 0.5
    fs, signal_int16 = wavfile.read("audiomono.wav")
    signal = signal_int16.astype(np.float64) / 2**15
    
    delay_len_samples = round(ECHO_DURATION * fs)
    leading_zero_padding_signal = np.zeros(delay_len_samples)

    delayed_signal = np.concatenate((leading_zero_padding_signal, signal))
    signal = np.concatenate((signal, leading_zero_padding_signal))

    summed_signal = signal + DELAY_AMPLITUDE * delayed_signal

    wavfile.write("output.wav", fs, summed_signal)
    plt.figure()
    plt.plot(signal)
    plt.show()
    plt.plot(delayed_signal)
    plt.show()
    plt.plot(summed_signal)
    plt.show()