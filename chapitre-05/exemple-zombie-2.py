#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-zombien-2.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import time

if (os.fork() != 0):
	print("[PARENT] My PID is", os.getpid())
	time.sleep(2)
	print("[PARENT] Terminating now!")

else:
	for i in range(1,5):
		print("[CHILD] My parent is", os.getppid())
		time.sleep(1)

