import serial
import time


arduino = serial.Serial('COM12', 9600, timeout=1)  

time.sleep(2)  

print("Esperando datos del Arduino...")

try:
    while True:
        # Lee la línea del puerto serial
        if arduino.in_waiting > 0:
            data = arduino.readline().decode('utf-8').strip()  
            if data:
               
                angle, distance = data.split(',')
                print(f"Angle: {angle}°, Distance: {distance} cm")
except KeyboardInterrupt:
    print("\nPrograma detenido por el usuario.")
finally:
    arduino.close()  
