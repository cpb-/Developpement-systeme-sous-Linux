#! /usr/bin/python
from __future__ import print_function
import os
import stat
import sys

sys.argv.pop(0)
for f in sys.argv:
	try:
		print(f, os.readlink(f))
