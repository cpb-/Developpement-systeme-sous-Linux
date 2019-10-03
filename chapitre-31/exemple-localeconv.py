#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-localconv.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import locale

locale.setlocale(locale.LC_ALL, "")
database = locale.localeconv()
for key in database:
	print(key,database[key])
