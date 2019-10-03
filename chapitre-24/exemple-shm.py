#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-shm.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import mmap
import os
import struct
import sys
import time

if len(sys.argv) < 2:
	print("usage:", sys.argv[0], "shm-file")
	sys.exit(1)
try:
	stat = os.stat(sys.argv[1])
	size = stat.st_size;
	fd = os.open(sys.argv[1], os.O_RDWR)
	mapping = mmap.mmap(fd, size, mmap.MAP_SHARED, mmap.PROT_READ | mmap.PROT_WRITE)
except:
	print("Wrong file :", sys.argv[1])
	sys.exit(1)

while True:
	(counter,) = struct.unpack("i", mapping[:])
	counter = counter + 1
	struct.pack_into("i", mapping, 0, counter)
	print(counter)
	time.sleep(1)
