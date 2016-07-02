#! /usr/bin/python
from __future__ import print_function
import os

(fd_r, fd_w) = os.pipe()
w = "Hello Python's world"
n = os.write(fd_w, w)
r = os.read(fd_r, 4096)
if r == w:
	print("Ok")


