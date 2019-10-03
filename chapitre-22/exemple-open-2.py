#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-open-2.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
	
try:
	fd = os.open("essai.open", os.O_RDWR | os.O_CREAT | os.O_EXCL, 0777)
	os.close(fd)
except OSError:
	print("Error")

