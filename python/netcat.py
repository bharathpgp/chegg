import socket               
import sys

#reading commandline arguments
option	= sys.argv[1]
ip	= sys.argv[2]
port	= sys.argv[3]
prot	= sys.argv[4]

#Listener part to listen on the user supplied host, port and protocol 
if option == "-L":
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((ip, int(port)))
	s.listen(2)

	while True:
	   c, addr = s.accept()     
	   print c.recv(1024)

#Talker part to emit the user supplied host, port and protocol
if option == "-S":
	c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	c.connect((ip, int(port)))
	c.send("ip = " + ip)
	c.send(" port = " + port)
	c.send(" protocol = " + prot)



