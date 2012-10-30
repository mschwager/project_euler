	# Author: Matt Schwager
	# schwag09@gmail.com
	# Project Euler problem 29
	# Integer combinations for powers

#!usr/bin/python

def main():
	print len(set(i**j for i in range(2,101) for j in range(2,101)))

if __name__ == "__main__":
	main()
