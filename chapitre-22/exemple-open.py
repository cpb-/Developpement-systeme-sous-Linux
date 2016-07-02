#! /usr/bin/python
from __future__ import print_function

import os

def open_file(name, label, mode):
	print("os.open({}, {}) :".format(name, label), end='')
	try:
		fd = os.open(name, mode, 0640)
		os.close(fd)
		print("Ok")
	except OSError:
		print("Error")

open_file("/etc/passwd", "O_RDONLY",
                           os.O_RDONLY)
open_file("/etc/passwd", "O_RDWR",
                           os.O_RDWR)
open_file("essai.fopen",  "O_RDONLY",
                           os.O_RDONLY)
open_file("essai.fopen",  "O_RDONLY | O_CREAT",
                           os.O_RDONLY|os.O_CREAT)
open_file("essai.fopen",  "O_RDWR | O_CREAT | O_EXCL", 
                           os.O_RDWR | os.O_CREAT | os.O_EXCL)

