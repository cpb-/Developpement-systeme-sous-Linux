#! /usr/bin/python
from __future__ import print_function
import os
	
try:
	fd = os.open("essai.open", os.O_RDWR | os.O_CREAT | os.O_EXCL, 0777)
	os.close(fd)
except OSError:
	print("Error")

