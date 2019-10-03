#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-popen.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import Tkinter
import sys

class DialogBox:
	def __init__(self, window, title, label, default_value):
		self.window = window
		self.window.title(title)
		Tkinter.Label(self.window, text=label).pack(padx=5, pady=5)
		self.entry = Tkinter.Entry(self.window)
		self.entry.pack(padx=5, pady=5)
		self.entry.insert(0, default_value)
		self.default_value = default_value
		frame = Tkinter.Frame(self.window)
		frame.pack()
		bt = Tkinter.Button(frame, text="Ok", command=self.bt_ok)
		bt.pack(padx=5, pady=5, side=Tkinter.LEFT)
		bt = Tkinter.Button(frame, text="Cancel", command=self.bt_cancel)
		bt.pack(padx=5, pady=5, side=Tkinter.LEFT)

	def bt_ok(self):
		print(self.entry.get())
		self.window.destroy()

	def bt_cancel(self):
		print(self.default_value)
		self.window.destroy()

if len(sys.argv) < 4:
	print("usage: " + sys.argv[0] + " title label default", file=sys.stderr)
	sys.exit(1)

root_window = Tkinter.Tk()
dialog_box  = DialogBox(root_window, sys.argv[1], sys.argv[2], sys.argv[3])
root_window.wait_window(dialog_box.window)

