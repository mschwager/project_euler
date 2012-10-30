#!usr/bin/python

def main():
	index = 1
	text = "."
	while len(text) <= 1000000:
		text += str(index)
		index += 1
	print int(text[1]) * int(text[10]) * int(text[100]) * int(text[1000]) * int(text[10000]) * int(text[100000]) * int(text[1000000])

if __name__ == "__main__":
	main()
