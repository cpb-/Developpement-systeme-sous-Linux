#! /usr/bin/python

from __future__ import print_function
import os

for g in os.getgroups():
	print(g, end=' ')
print()
