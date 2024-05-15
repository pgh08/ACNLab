from socket import *

sAdd = '127.0.0.1'
sPort = 12345

cSocket = socket(AF_INET, SOCK_STREAM)
cSocket.connect((sAdd, sPort))

while True:
	msg = input("Reply : ")
	cSocket.send(msg.encode())
	msgFromServer = cSocket.recv(1024).decode()
	print("Server : ", msgFromServer)
	
	if msgFromServer == 'bye':
		break;
		
cSocket.close()
