#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-mmap-1.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
from __future__ import print_function
import mmap
import os
import sys

if len(sys.argv) < 2:
	print("usage:", sys.argv[0], "file")
	sys.exit(1)

try:
	stat = os.stat(sys.argv[1])
	size = stat.st_size;
	fd = os.open(sys.argv[1], os.O_RDWR)
	mapping = mmap.mmap(fd, size, mmap.MAP_SHARED, mmap.PROT_READ | mmap.PROT_WRITE)
	for i in range (0, size / 2):
		tmp = mapping[i]
		mapping[i] = mapping[size - i - 1]
		mapping[size - i - 1] = tmp

except:
	print("Wrong file :", sys.argv[1])
	sys.exit(1)
