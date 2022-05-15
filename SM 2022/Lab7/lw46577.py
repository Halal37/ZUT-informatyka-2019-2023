import scipy.fftpack
import sounddevice as sd
import soundfile as sf
import numpy as np
import matplotlib.pyplot as plt
from pylab import rcParams


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

def quantize2(data, bits, minimal_value, maximum_value):
    out_val = data.astype(np.float32)
    quant = 2**bits-1

    out_val = (out_val-minimal_value)/(maximum_value-minimal_value)
    out_val = np.round(out_val*quant)/quant
    out_val = ((out_val*(maximum_value-minimal_value))+minimal_value)
    return out_val.astype(data.dtype)


def encode_mu_law(data, u):
    assert data.min() >= -1 and data.max() <= 1 and np.issubdtype(data.dtype, np.floating)
    out_val = np.sign(data) * (np.log(1+u*np.abs(data)) / np.log(1+u))
    return out_val


def decode_mu_law(data, u):
    assert data.min() >= -1 and data.max() <= 1 and np.issubdtype(data.dtype, np.floating)
    out_val = np.sign(data) * (1/u) * (np.power(1+u, np.abs(data))-1)
    return out_val

def encode_DPCM(data, bits):
    out_val = data.copy()
    E = out_val[0]
    for x in range(1, data.shape[0]):
        diff = data[x] - E
        diff = quantize2(diff, bits, data.min(), data.max())
        out_val[x] = diff
        E += diff
    return out_val


def decode_DPCM(data):
    out_val = data.copy()
    for x in range(1, data.shape[0]):
        out_val[x] = out_val[x - 1] + data[x]
    return out_val

data, freq = sf.read('sounds/sing_low1.wav', dtype=np.float32)

print(freq, data.shape, np.unique(data).size)
if len(data.shape) > 1:
    data = data[:, 0]

bit = 2
time_ms = 2000
max = int(freq*(time_ms/1000))

data1 = encode_mu_law(data[0:max], 255)
data1 = quantize(data1, bit)
data1 = decode_mu_law(data1, 255)

data2 = encode_DPCM(data[0:max], bit)
data2 = decode_DPCM(data2)

sd.play(data[0:max], samplerate=freq, blocking=True)
#Mu_law
sd.play(data1, samplerate=freq, blocking=True)
#DPCM
sd.play(data2, samplerate=freq, blocking=True)
