#!usr/bin/python

def main():
	result = 0
	for i in range(2, 1000001):
		if i == sum(int(j)**5 for j in str(i)):
			result += i
	print result	

if __name__ == "__main__":
	main()
