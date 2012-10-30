#!usr/bin/python

#VERY SLOW! NEEDS OPTIMIZATION

def sieve(number):
	numList = range(0, number+1)
	index = 1
	while index**2 < number:
		index += 1
		if numList[index] == 0:
			continue
		if index > 2:
			step = 2 * index
		else:
			step = index
		for j in range(index**2, number+1, step):
			numList[j] = 0
	numList[1] = 0
	result = []
	for i in numList:
		if i != 0:
			result.append(i)
	return result

def circular(numList):
	result = []
	isCircular = True
	for i in numList:
		k = str(i)
		leng = len(k)
		isCircular = True
		for j in range(1, leng):
			k += k[j-1]
			if numList.count(int(k[j:])) == 0:
				isCircular = False
				break
		if isCircular:
			print i, " is circular"
			result.append(i)
	return result

def main():
	numList = sieve(1000000)
	numList = circular(numList)	
	print len(numList)

if __name__ == "__main__":
	main()
