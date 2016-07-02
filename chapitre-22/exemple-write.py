#! /usr/bin/python
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


