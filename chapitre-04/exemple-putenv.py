#! /usr/bin/python

from __future__ import print_function
import os

def recherche_variable(var):
	try:
		print("  variable", var + "=" + os.environ[var])
	except:
		print("  variable", var, "non definie")

recherche_variable("ESSAI")
print('os.environ["ESSAI"] = "UN"')
os.environ["ESSAI"] = "UN"
recherche_variable("ESSAI")
print('os.environ["ESSAI"] = "DEUX"')
os.environ["ESSAI"] = "DEUX"
recherche_variable("ESSAI")
print('del os.environ["ESSAI"]')
del os.environ["ESSAI"]
recherche_variable("ESSAI")


