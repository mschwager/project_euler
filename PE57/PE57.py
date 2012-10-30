#!usr/bin/python

def main():
	result = 0
	expansionCount = 2
	num, denom, prevnum, prevdenom = 7, 5, 3, 2
	for i in range(0, 1000):
		num, prevnum = (2 * num) + prevnum, num	
		denom, prevdenom = (2 * denom) + prevdenom, denom	
		if len(str(num)) > len(str(denom)):
			result += 1
	print result

if __name__ == "__main__":
	main()
