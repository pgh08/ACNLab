from socket import *

sAdd = '127.0.0.1'
sPort = 12345

sSocket = socket(AF_INET, SOCK_STREAM)
sSocket.bind((sAdd, sPort))
sSocket.listen(1)

print("Server is UP and Running")
conn, add = sSocket.accept()
print(f"Server is connected to client {add}")

while True:
	msgFromClient = conn.recv(1024).decode()
	print("Client : ", msgFromClient)
	msg = input("Reply : ")
	conn.send(msg.encode())
	
	if msgFromClient == 'bye':
		break;
		
conn.close()
