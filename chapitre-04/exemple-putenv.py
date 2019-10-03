#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-putenv.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

def find_var(var):
	try:
		print("  variable", var + "=" + os.environ[var])
	except:
		print("  variable", var, "doesn't exist")

find_var("ESSAI")
print('os.environ["ESSAI"] = "UN"')
os.environ["ESSAI"] = "UN"
find_var("ESSAI")
print('os.environ["ESSAI"] = "DEUX"')
os.environ["ESSAI"] = "DEUX"
find_var("ESSAI")
print('del os.environ["ESSAI"]')
del os.environ["ESSAI"]
find_var("ESSAI")
