#! /usr/bin/python
from __future__ import print_function
import locale

locale.setlocale(locale.LC_ALL, "")
database = locale.localeconv()
for key in database:
	print(key,database[key])
