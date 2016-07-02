#! /usr/bin/python

from __future__ import print_function
import os

arg = [ 'sh', '-c', 'echo $SHLVL' ]

print("Running: /bin/sh -c 'echo $SHLVL'");
try:
	os.execve('/bin/sh', arg, os.environ)
except OSError:
	print("Failed")


