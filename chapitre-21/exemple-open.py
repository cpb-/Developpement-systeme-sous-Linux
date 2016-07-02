#! /usr/bin/python
from __future__ import print_function

def open_file(name, mode):
	print("open({}, {}) :".format(name, mode), end='')
	try:
		f = open(name, mode)
		f.close()
		print("Ok")
	except IOError:
		print("Error")

open_file("/etc/inittab", "r")
open_file("/etc/inittab", "w")
open_file("essai.fopen",  "r")
open_file("essai.fopen",  "w")
open_file("essai.fopen",  "r")

