#!usr/bin/python

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

def truncLeft(number):
	result = []
	length = len(str(number))
	for i in range(1, length):
		result.append(str(number)[i:])
	return result

def truncRight(number):
	result = []
	length = len(str(number))
	for i in range(1, length):
		result.append(str(number)[:i])
	return result

def main():
	result, isTrunc, count = -17, True, -4
	numList = sieve(1000000)
	for i in numList:
		isTrunc = True
		left = truncLeft(i)
		right = truncRight(i)
		for j in left:
			if numList.count(int(j)) == 0:
				isTrunc = False
		for k in right:
			if numList.count(int(k)) == 0:
				isTrunc = False
		if isTrunc:
			count += 1
			result += i
			print "Sum: ", result, "Count: ", count				
		if count == 11:
			break
	print "Sum: ", result, "Count: ", count				

if __name__ == "__main__":
	main()
