#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-getaddrinfo-02.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import socket
import sys

sys.argv.pop(0)
for var in sys.argv:
	try:
		print(var, end=': ')
		result = socket.getaddrinfo(None, var, socket.AF_INET, 0, 0)
	except:
		print("Error")
		continue
	for (family, socktype, proto, canon, sockaddr) in result:
		(host, port) = socket.getnameinfo(sockaddr, socket.NI_NUMERICSERV)
		print(port, end=' ')
	print('')

