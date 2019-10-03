#! /usr/bin/python3
# ------------------------------------------------------------------
# exemple-setaffinity.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
import os

nb_cpu = os.sysconf(os.sysconf_names['SC_NPROCESSORS_ONLN'])
while True:
	for i in range(0, nb_cpu):
		cpuset = [i]
		os.sched_setaffinity(0, cpuset)
		for j in range(0,100000000):
			pass

