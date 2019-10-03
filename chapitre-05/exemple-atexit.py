#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-atexit.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import atexit
import sys

def out_1():
	print("out_1(): calling sys.exit()")
	sys.exit(0)

def out_2():
	print("out_2()")

def out_3():
	print("out_3()")


atexit.register(out_3)
atexit.register(out_2)
atexit.register(out_2)
atexit.register(out_1)
print("Normal termination at end of script.")
