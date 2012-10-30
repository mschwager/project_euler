#!/bin/bash/python

from math import factorial

def main():
	count = 0
	for i in range(1, 101):
		for j in range(1, i):
			if C(i, j) > 1000000:
				count += 1
	print count

def C(n, r):
	return factorial(n)/(factorial(r) * factorial(n-r))

if __name__ == "__main__":
	main()
