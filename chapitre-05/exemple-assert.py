#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-assert.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function

def succeeding_function(num):
	assert (num >= 0), "Le nombre doit etre positif ou nul"
	print("Ok,", num, "est positif")

def failing_function(num):
	assert (num <= 0), "Le nombre doit etre negatif ou nul"
	print("Ok,", num, "est negatif")



succeeding_function(5)
failing_function(5)

