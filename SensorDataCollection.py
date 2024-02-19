import serial

# Assuming the sensor is connected to COM3 at 9600 baud rate
ser = serial.Serial('COM3', 9600)

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').rstrip()
        print(f"Sensor data: {data}")
