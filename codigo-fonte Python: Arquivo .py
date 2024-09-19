import pyaudio
import numpy as np
import serial
import struct
import time
import tkinter as tk
from emoji import emojize
import colorsys

arduino = serial.Serial('COM3', 115200, timeout=.1)
np.set_printoptions(suppress=True)

CHUNK = 4096
RATE = 44100

p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16, channels=1,
rate=RATE, input=True, frames_per_buffer=CHUNK)

def update_gui(freq_peak):
 frequency_label.config(text="Frequência: {}
Hz".format(freq_peak))

 # Adicionando emojis com base na intensidade
do som
 intensity = int(freq_peak / 1400 * 100) # Normaliza
a intensidade para um valor entre 0 e 100
 emoji = "😊" if intensity > 50 else "😢"
 emoji_label.config(text=emoji)

 # Adicionando animação baseado na intensidade
do som
 canvas.delete("all") # Limpa o Canvas

 # Criando uma paleta de cores do arco-íris
 rainbow_colors = [colorsys.hsv_to_rgb(x / 100, 1.0,
1.0) for x in range(0, 101)]

 # Garanta que o índice esteja dentro dos limites
 color_index = max(0, min(intensity, 100))
 fill_color = "#{:02x}{:02x}{:02x}".format(
 int(rainbow_colors[color_index][0] * 255),
 int(rainbow_colors[color_index][1] * 255),
 int(rainbow_colors[color_index][2] * 255)
 )

 canvas.create_rectangle(10, 10, 10 + intensity, 30,
fill=fill_color)

 # ...
def start_detection():
 try:
 while True:
 data = np.fromstring(stream.read(CHUNK),
dtype=np.int16)
 data = data * np.hanning(len(data))
 fft = abs(np.fft.fft(data).real)
 fft = fft[:int(len(fft) / 2)]
 freq = np.fft.fftfreq(CHUNK, 1.0 / RATE)
 freq = freq[:int(len(freq) / 2)]
 freq_peak = freq[np.where(fft ==
np.max(fft))[0][0]] + 1
 print("peak frequency: %d Hz" % freq_peak)

 if 300 < freq_peak <= 500:
 arduino.write(struct.pack('>B', 1))
 elif 500 < freq_peak <= 800:
 arduino.write(struct.pack('>B', 2))
 elif 800 < freq_peak <= 1000:
 arduino.write(struct.pack('>B', 3))
 elif 1000 < freq_peak <= 1150:
 arduino.write(struct.pack('>B', 4))
 elif 1150 < freq_peak <= 1200:
 arduino.write(struct.pack('>B', 5))
 elif 1200 < freq_peak <= 1300:
 arduino.write(struct.pack('>B', 6))
 elif 1300 < freq_peak <= 1400:
 arduino.write(struct.pack('>B', 7))
 else:
 arduino.write(struct.pack('>B', 0))

 update_gui(freq_peak)
 root.update_idletasks()
 root.update()
