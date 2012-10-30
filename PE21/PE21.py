#!usr/bin/python

def isAmicable(value):
	sum1, sum2 = 0, 0
	for i in range(1, int(value/2) + 1):
		if value % i == 0:
			sum1 += i
	for j in range(1, int(sum1/2) + 1):
		if sum1 % j == 0:
			sum2 += j
	if value == sum2 and value != sum1:
		return True
	return False

def main():
	result = 0
	for i in range(1, 10001):
		if isAmicable(i):
			result += i
	print result

if __name__ == "__main__":
	main()
