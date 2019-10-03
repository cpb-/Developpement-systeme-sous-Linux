#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-write.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import resource
import os

TAILLE_BLOC = 1024
DEPASSEMENT = 767

limit = 3 * TAILLE_BLOC + DEPASSEMENT
resource.setrlimit(resource.RLIMIT_FSIZE, (limit, limit));

fd = os.open("essai.write", os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0644)
s = "1" * TAILLE_BLOC

while True:
	n = os.write(fd, s)
	print(n, "bytes written");


