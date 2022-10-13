#!/usr/bin/env python3
# 19BCE245 - Aayush Shah

# Importing necessary libraries
import socket
s = socket.socket() # Initialising a socket
s.bind(('localhost', 9999))
s.listen()
while True:
	# Accepting a connection request from client and printing it 
	c, address = s.accept()
	print('Connection request from {} accepted.'.format(address)) 
	print(c.recv(1024).decode()) # Receiving echo message 
	print('Sending acknowledgement message') 
	c.send('Acknowledgement message received'.encode()) # Sending acknowledgement for the received message
	c.close()