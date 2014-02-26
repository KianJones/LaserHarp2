import serial
import os

ser = serial.Serial("COM5",9600,timeout=5)

while True:
    try:
        x = ser.readline()
        if x[0] == "r":
            os.startfile(r'LaserHarp2-master\clarinet\clarinet1.pp.aiff')
        if x[0] == "y":
            os.startfile(r'LaserHarp2-master\clarinet\clarinet2.pp.aiff')
        if x[0] == "g":
            os.startfile(r'LaserHarp2-master\clarinet\clarinet3.pp.aiff')
    except KeyboardInterrupt:
        break
    
