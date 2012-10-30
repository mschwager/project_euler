	# Author: Matt Schwager
	# schwag09@gmail.com
	# Project Euler problem 26
	# Reoccuring fraction cycles

#!usr/bin/python
from decimal import *

def cycleSize(num, curCycle):
	# Check if the current cycle length is atleast longer than the
	# current numbers amount of digits
	if curCycle > len(num[2:]):
		return 0
	for i in num[2:]:
			

def main():
	# result and current are tuples containing firstly the longest cycle
	# and secondly the denominator
	result = 0, 0
	current = 0, 0
	getcontext().prec = 100

	for i in range(2, 1000):
		current[0] = cycleSize(str(Decimal(1) / Decimal(i)), result[0])
		if current[0] > result[0]:
			result = current[0], i
	print result

if __name__ == "__main__":
	main()
