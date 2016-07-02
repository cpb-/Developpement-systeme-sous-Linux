#! /usr/bin/python

from __future__ import print_function
import os

args = [ "ls", "-l", "-n" ]

try:
	os.execvp(args[0], args)
except OSError:
	print("Error, unable to run", args[0])
