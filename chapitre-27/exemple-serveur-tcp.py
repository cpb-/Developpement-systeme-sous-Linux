#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-serveur-tcp.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import socket
import sys

def tcp_server(service_name):
	try:
		result = socket.getaddrinfo(None, service_name,
			 socket.AF_INET, 0, 0, socket.AI_PASSIVE)
	except:
		print("Invalid service name:", service_name)
		sys.exit(1)

	(family, socktype, proto, canon, sockaddr) = result[0]

	server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	try:
		server_sock.bind(sockaddr)
	except:
		print("Error in bind")

	(addr, port) = server_sock.getsockname()
	print("My port number is", port)

	server_sock.listen(5)

	while True:
		(connected_sock, address) = server_sock.accept()
		
		if (os.fork() == 0):
				server_sock.close()
				print("Connection from", address)
				os.write(connected_sock.fileno(),
					"Connection from "
					+str(address)+"\n")
				sys.exit(0)
		else:
			connected_sock.close()

tcp_server("5000")
