#!/usr/bin/env python3
# 19BCE245 - Aayush Shah

# Importing necessary libraries
import socket
r = socket.socket()  # Initialising a socket
print('Sending connection request to {}/{}'.format('localhost', 9999)) 
r.connect(('localhost', 9999)) # Sending a connection request to localhostprint('Sending echo message')
r.send('Echo message'.encode()) # Sending echo message
# Receiving acknowledgement from sever and printing it
ack = r.recv(1024).decode()
print('Acknowledgement received')
print(ack)
r.close()