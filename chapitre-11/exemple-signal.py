#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-signal.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import signal
import os

def handler(num, stack):
	print("Signal", num, "received")

for sig in range(1, signal.NSIG):
	try:
		signal.signal(sig, handler)
	except:
		print("Unable to catch signal", sig)

while True:
	signal.pause()
