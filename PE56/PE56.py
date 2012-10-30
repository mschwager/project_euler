#!usr/bin/python

def main():
	result = 0
	curBest = 0
	for i in range(1, 100):
		for j in range(1, 100):
			result = sum(int(x) for x in str(i**j))
			if result > curBest:
				curBest = result
	print curBest

if __name__ == "__main__":
	main()
