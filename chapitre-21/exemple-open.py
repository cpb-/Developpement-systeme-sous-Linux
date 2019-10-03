#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-open.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
from __future__ import print_function

def open_file(name, mode):
	print("open({}, {}) :".format(name, mode), end='')
	try:
		f = open(name, mode)
		f.close()
		print("Ok")
	except IOError:
		print("Error")

open_file("/etc/passwd", "r")
open_file("/etc/passwd", "w")
open_file("essai.fopen",  "r")
open_file("essai.fopen",  "w")
open_file("essai.fopen",  "r")

