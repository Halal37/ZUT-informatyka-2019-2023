import numpy as np
from pylab import rcParams
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d
import scipy.fftpack
import soundfile as sf


def quantize(data, bits):
    assert 2 <= bits <= 32

    out_val = data.astype(np.float32)
    minimal_value = 0
    maximum_value = 0

    if np.issubdtype(data.dtype, np.floating):
        minimal_value = -1
        maximum_value= 1
    else:
        minimal_value = np.iinfo(data.dtype).min
        maximum_value   = np.iinfo(data.dtype).max

    quant = 2**bits-1

    out_val = (out_val-minimal_value)/(maximum_value-minimal_value)
    out_val = np.round(out_val*quant)/quant
    out_val = ((out_val*(maximum_value-minimal_value))+minimal_value).astype(data.dtype)
    return out_val


def decimation(signal, N):
    return signal[::N].copy()


def interp_signal(data, freq, new_freq, interp_type="linear"):
    time = data.shape[0]/freq
    x  = np.arange(0, time, 1/freq)
    x1 = np.arange(0, time, 1/new_freq)

    func = interp1d(x, data, interp_type, fill_value="extrapolate")
    return func(x1).astype(data.dtype)


def plot_sound(data, freq, time_ms, title="???"):
    max = int(freq*(time_ms/1000))
    plt.subplot(2, 1, 1)
    plt.plot(np.arange(0, max)/freq, data[0:max])
    plt.subplot(2, 1, 2)
    plot_spectrum(data, freq)
    plt.title(title)
    plt.tight_layout()

    plt.show()


def plot_spectrum(data, freq):
    fsize = 2 ** 8
    yf = scipy.fftpack.fft(data, fsize)
    plt.plot(np.arange(0, freq / 2, freq / fsize), 20 * np.log10(np.abs(yf[:fsize // 2])))


def plotfreq_change(data, old_freq, new_freq, time_ms,name):
    plt.subplot(3, 1, 1)
    plot_spectrum(decimation(data, int(old_freq / new_freq)), new_freq)
    plt.title("Decimation (" + str(new_freq) + "Hz)")
    plt.subplot(3, 1, 2)
    plot_spectrum(interp_signal(data, old_freq, new_freq, "linear"), new_freq)
    plt.title("Linear interpolation (" + str(new_freq) + "Hz)")
    plt.subplot(3, 1, 3)
    plot_spectrum(interp_signal(data, old_freq, new_freq, "cubic"), new_freq)
    plt.title("Cubic interpolation (" + str(new_freq) + "Hz)")
    plt.tight_layout()

    plt.show()


rcParams['figure.figsize'] = 10, 10
def plot(file):

    data, freq = sf.read(file, dtype=np.int32)
    print(freq, data.shape)
    if len(data.shape) > 1:
      data = data[:, 0]

    ms = 100
    plot_sound(quantize(data, 4),  freq, ms, "Quantization 4 bit")
    plot_sound(quantize(data, 8),  freq, ms, "Quantization 8 bit")
    plot_sound(quantize(data, 16), freq, ms, "Quantization 16 bit")
    plot_sound(quantize(data, 24), freq, ms, "Quantization 24 bit")

    plotfreq_change(data, freq, 2000 , ms,file)
    plotfreq_change(data, freq, 4000 , ms,file)
    plotfreq_change(data, freq, 8000 , ms,file)
    plotfreq_change(data, freq, 16000, ms,file)
    plotfreq_change(data, freq, 24000, ms,file)
    plotfreq_change(data, freq, 41000, ms,file)
    plotfreq_change(data, freq, 16950, ms,file)

plot('E:/SM/sounds/sin_60Hz.wav')
plot('E:/SM/sounds/sin_440Hz.wav')
plot('E:/SM/sounds/sin_8000Hz.wav')



