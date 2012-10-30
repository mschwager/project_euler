#!usr/bin/python

from math import factorial

def isFact(number):
	summation = sum(factorial(int(i)) for i in str(number))
	if number == summation:
		return True
	return False

def main():
	print sum(i for i in range(3, 1000001) if isFact(i))

if __name__ == "__main__":
	main()
