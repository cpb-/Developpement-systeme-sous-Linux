#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-nonblock-1.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import fcntl
import time

(fd_r, fd_w) = os.pipe()
n = 0
fcntl.fcntl(fd_w, fcntl.F_SETFL, os.O_NONBLOCK)
while True:
	try:
		os.write(fd_w, 'c')
		n = n +1
		print("Written bytes:", n)
	except Exception as e:
		print(str(e))
		time.sleep(1)


