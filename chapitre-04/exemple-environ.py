#! /usr/bin/python

from __future__ import print_function
import os

for v in os.environ:
	print(v + "=" + os.environ[v])
