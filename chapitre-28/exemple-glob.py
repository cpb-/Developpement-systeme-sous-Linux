#! /usr/bin/python
from __future__ import print_function
import glob
import sys

for f in glob.glob(sys.argv[1]):
	print(f)
