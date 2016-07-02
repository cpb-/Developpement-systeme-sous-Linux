#! /usr/bin/python

from __future__ import print_function
import atexit
import sys

def sortie_1():
	print("Sortie_1: calling sys.exit()")
	sys.exit(0)

def sortie_2():
	print("Sortie_2")

def sortie_3():
	print("Sortie_3")


atexit.register(sortie_3)
atexit.register(sortie_2)
atexit.register(sortie_2)
atexit.register(sortie_1)
print("Normal termination at end of script.")
