#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-wait-1.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import signal
import sys
import time

for num_fils in range(0, 3):
	if (os.fork() == 0):
		if (num_fils == 0):
			sys.exit(1)
		elif (num_fils == 1):
			sys.exit(2)
		else:
			os.kill(0, signal.SIGUSR1)
	else:
		while True:
			try:
				(pid, status) = os.wait()
				if (os.WIFEXITED(status)):
					print("Le processus", pid,
					      "s'est termine normalement avec le code",
					      os.WEXITSTATUS(status))
				elif (os.WIFSIGNALED(status)):
					print("Le processus", pid,
					      "a ete tue par le signal",
					      os.WTERMSIG(status))
					if (os.WCOREDUMP(status)):
						print("Fichier core cree")
			except:
				break


