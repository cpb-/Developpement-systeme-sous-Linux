#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-fcntl-2.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import fcntl
import os
import sys

def access_test(fd, name):
	etat = fcntl.fcntl(fd, fcntl.F_GETFL)
	etat = etat & (os.O_RDWR | os.O_RDONLY | os.O_WRONLY)
	if etat == os.O_RDWR:
		print(name, ": R/W")
	else:
		if etat == os.O_RDONLY:
			print(name, ": R")
		else:
			print(name, ": W")

access_test(sys.stdin.fileno(), "stdin")
access_test(sys.stdout.fileno(), "stdout")
access_test(sys.stderr.fileno(), "stderr")

