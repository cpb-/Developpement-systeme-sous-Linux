#! /usr/bin/python

from __future__ import print_function

def fonction_reussissant(num):
	assert (num >= 0), "Le nombre doit etre positif ou nul"
	print("Ok,", num, "est positif")

def fonction_echouant(num):
	assert (num <= 0), "Le nombre doit etre negatif ou nul"
	print("Ok,", num, "est negatif")



fonction_reussissant(5)
fonction_echouant(5)

