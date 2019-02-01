import socket

my_soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_soc.connect(('www.py4inf.com', 80))

my_soc.send('GET http://www.py4inf.com/code/romeo.txt HTTP/1.0\n\n')
while True:
    data = my_soc.recv(512)
    if len(data) < 1:
	break;
    print data
my_soc.close()
