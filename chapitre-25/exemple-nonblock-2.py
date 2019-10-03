#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-nonblock-2.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import fcntl
import time

(fd_r, fd_w) = os.pipe()

if os.fork() == 0:
	while True:
		os.write(fd_w, 'c')
		time.sleep(0.7)
else:
	fcntl.fcntl(fd_r, fcntl.F_SETFL, os.O_NONBLOCK)
	while True:
		try:
			r = os.read(fd_r, 1)
			print("Ok")
		except:
			print("Error")
		time.sleep(0.1)


