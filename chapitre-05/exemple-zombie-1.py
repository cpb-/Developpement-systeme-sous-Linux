#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-zombie-1.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import sys
import time

pid = os.fork()

if (pid == 0):
	time.sleep(2)
	print("Child process will terminate now!")

else:
	for i in range(1,5):
		os.system("ps {0}".format(pid))
		time.sleep(1)

sys.exit(0)
