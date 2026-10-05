import numpy as np
import sounddevice as sd

SAMPLE_RATE = 44100

def play_tone(frequency, duration):
    samples = int(SAMPLE_RATE * duration)

    t = np.linspace(
        0,
        duration,
        samples,
        endpoint=False
    )

    tone = np.sin(2 * np.pi * frequency * t)

    sd.play(tone, SAMPLE_RATE)
    

def stop():
    sd.stop()
