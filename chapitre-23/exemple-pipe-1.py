#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-pipe-1.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

(fd_r, fd_w) = os.pipe()
w = "Hello Python's world"
n = os.write(fd_w, w)
r = os.read(fd_r, 4096)
if r == w:
	print("Ok")


