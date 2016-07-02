#! /usr/bin/python
from __future__ import print_function
import locale
import sys
import time

locale.setlocale(locale.LC_ALL,'')
sys.argv.pop(0)
for arg in sys.argv:
	print(time.strftime(arg))

