	# Author: Matt Schwager
	# schwag09@gmail.com
	# Project Euler problem 33
	# Fractions with an unorthodox cancelling method

#!usr/bin/python

def isUnorthodox(num, den):
	if (num % 10 == 0) or (den % 10 == 0):
		return False
	frac = float(num)/float(den)
	if(str(num)[0] == str(den)[0] and float(str(num)[1]) / float(str(den)[1]) == frac or
	   str(num)[1] == str(den)[0] and float(str(num)[0]) / float(str(den)[1]) == frac or
	   str(num)[0] == str(den)[1] and float(str(num)[1]) / float(str(den)[0]) == frac or
	   str(num)[1] == str(den)[1] and float(str(num)[0]) / float(str(den)[0]) == frac):
	   return True
	return False
	
def main():
	numResult, denResult = 1, 1
	for num in range(10, 100):
		for den in range(num + 1, 100):
			if isUnorthodox(num, den):
				print num, "/", den
				numResult *= num
				denResult *= den
	print numResult, "/", denResult

if __name__ == "__main__":
	main()
