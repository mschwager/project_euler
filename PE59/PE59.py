#!usr/bin/python

from itertools import permutations

def encryptXOR(numList, x, y, z):
	result = [0] * len(numList)
	for i in range(0, len(numList), 3):
		result[i] = numList[i] ^ ord(x)
	for i in range(1, len(numList) - 1, 3):
		result[i] = numList[i] ^ ord(y)
	for i in range(2, len(numList) - 1, 3):
		result[i] = numList[i] ^ ord(z)
	return result

def main():

	#Read file
	tempList = []
	inFile = open('cipher1.txt', 'r')
	fileString = inFile.read();
	asciiList = fileString.split(',')
	asciiList[1200] = '73'

	for i in range(0, len(asciiList)):
		asciiList[i] = int(asciiList[i])
		
	#for x, y, z in permutations('ABCDEFGHIJKLMNOPQRSTUVWXYZ', 3):
		#tempList = encryptXOR(asciiList, x, y, z)
		#if asciiList == tempList:
			#print x, y, z
	
if __name__ == "__main__":
	main()
