#!/usr/bin/bash

def main():
	result = []
	resultVal = 0
	for i in range(1, 2000):
		for j in range(1, 2000):
			combString = str(i) + str(j) + str(i*j)
			if isPandigital(combString) and str(i*j) not in result:
				result.append(str(i*j))
				resultVal += (i*j)
	print resultVal
				
def isPandigital(inputString):
	if len(inputString) != 9:
		return False
	for i in range(1, 10):
		if str(i) not in inputString:
			return False
	return True

if __name__ == '__main__':
	main()
