#!usr/bin/python

from math import sqrt, ceil

def isPrime(num):
	if not (num % 2) and (num != 2):
		return False
	for i in range(3, int(ceil(sqrt(abs(num)))), 2):
		if not (num % i):
			return False
	return True

def main():
	primeCount, n, result = 0, 0, 0
	for a in range(-999, 1000):
		for b in range(-999, 1000):
			while isPrime(n*n + a*n + b):
				primeCount += 1
				n += 1
			if primeCount > result:
				result = primeCount
				print a, b
			primeCount = n = 0	
	print result

if __name__ == "__main__":
	main()
