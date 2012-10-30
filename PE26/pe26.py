#!/usr/bin/python

# http://mathworld.wolfram.com/DecimalExpansion.html

def decimal_expansion_cycle(n):
	remainders = []
	for i in range(n):
		if 10**i % n not in remainders:
			remainders.append(10**i % n)
		else:
			return i - remainders.index(10**i % n)

def main():
	print max([(i, decimal_expansion_cycle(i)) for i in range(1,1000)], key=lambda x: x[1])

if __name__ == "__main__":
	main()
