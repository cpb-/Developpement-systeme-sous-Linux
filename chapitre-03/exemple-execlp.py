#! /usr/bin/python

from __future__ import print_function
import os
import sys

i = 0
if len(sys.argv) == 2:
	try:
		i = int(sys.argv[1])
	except ValueError:
		print("Invalid value", sys.argv[1])
		sys.exit(1)
if i < 5:
	print("Counter =", (i+1))
	try:
		os.execlp(sys.argv[0], sys.argv[0], '{0}'.format(i+1))
	except OSError:
		print("Error, unable to run", sys.argv[0])

