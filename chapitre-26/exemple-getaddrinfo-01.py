#! /usr/bin/python
from __future__ import print_function
import socket
import sys

sys.argv.pop(0)
for var in sys.argv:
	try:
		print(var, end=': ')
		result = socket.getaddrinfo(var, 0, socket.AF_INET, 0, 0)
	except:
		print("Error")
		continue
	for (family, socktype, proto, canon, sockaddr) in result:
		(host, port) = socket.getnameinfo(sockaddr, 0)
		print(host, end=' ')
	print('')

