#! /usr/bin/python

from __future__ import print_function
import sys

print(sys.argv[0], "a recu en argument :")
sys.argv.pop(0)
for var in sys.argv:
	print(" ", var)
