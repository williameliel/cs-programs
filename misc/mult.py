#!/usr/bin/python

import string
from string import *

def ati(l, i):
	return l[len(l) - 1 - i]

def mult(a, b):
	if len(a) < len(b):
		t = a
		a = b
		b = t

	prod = [0] * (len(a) + len(b) + 1)

	for i in range(len(b)):
		# build pp
		pp = [0] * (len(a) + 1)
		c = 0
		for j in range(len(a)):
			p = (ati(b, i) * ati(a, j)) + c
			pp[len(pp) - 1 - j] = p % 10
			c = p / 10
		if c != 0:
			pp[0] = c

		# add pp to prod
		c = 0
		for j in range(len(pp)):
			s = ati(pp, j) + prod[len(prod) - 1 - i - j] + c
			c = s / 10
			prod[len(prod) - 1 - i - j] = s % 10
		if c != 0:
			prod[len(prod) - 1 - len(pp) - i] = c

	return prod

def listify(a):
	l = []
	a = list(a)
	for c in a:
		l = l + [atoi(c)]
	return l

def stringify(l):
	st = ""
	for i in l:
		st = st + str(i)
	return st

a = str(input("Enter first num: "))
b = str(input("Enter second num: "))

a = listify(a)
b = listify(b)

p = mult(a, b)
p = stringify(p)

print p
