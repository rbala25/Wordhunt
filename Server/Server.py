import socket
import time

import serial

arduino_port = '/dev/tty.usbmodem101'
arduino_baud = 9600
ser = serial.Serial(arduino_port, arduino_baud, timeout=1)

server_address = ('', 12345)
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(server_address)
server_socket.listen(1)

print(f"Python server listening on port {server_address[1]}...")

try:
    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Connection from {client_address}")

        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            messages = data.decode().strip().split('\n')

            counter = 0
            for message in messages:
                # print(counter)
                # counter += 1
                # time.sleep(1)

                # message = message.strip()
                # message += ";"
                if message:
                    ser.write((message + '\n').encode())
                    print(f"Sent message to Arduino: {message}")
                # print("here")
                time.sleep(1)

        client_socket.close()
        print(f"Connection closed from {client_address}")
        break

except Exception as e:
    print(f"Error: {e}")

finally:
    ser.close()
    server_socket.close()
    print("Server closed.")
