#! /usr/bin/python

from __future__ import print_function
import os
import sys

sys.argv.pop(0)
for var in sys.argv:
	try:
		print(var + "=" + os.environ[var])
	except:
		print(var, "non definie")
