	# Author: Matt Schwager
	# schwag09@gmail.com
	# Project Euler problem 43
	# Divisibility of 0-9 pandigitals

#!usr/bin/python

from itertools import permutations

def main():
	result			= 0
	permList		= list(permutations('9876543210', 10))

	for i in permList:
		if(int(''.join(i[7:10])) % 17 == 0 and
		   int(''.join(i[6:9])) % 13 == 0  and
		   int(''.join(i[5:8])) % 11 == 0  and
		   int(''.join(i[4:7])) % 7 == 0  and
	   	   int(''.join(i[3:6])) % 5 == 0 and
		   int(''.join(i[2:5])) % 3 == 0 and
		   int(''.join(i[1:4])) % 2 == 0):
			result += int(''.join(i))
			print int(''.join(i))
	
	print result

if __name__ == '__main__':
	main()
