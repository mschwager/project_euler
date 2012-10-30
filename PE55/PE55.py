#!usr/bin/python

def isLychrel(number):
	for i in range(1, 50):
		number += int(str(number)[::-1])
		if str(number) == str(number)[::-1]:
			return False
	return True

def main():
	print len([i for i in range(0, 10000) if isLychrel(i)])

if __name__ == "__main__":
	main()
