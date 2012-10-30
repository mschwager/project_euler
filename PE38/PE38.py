from Euler import is_pandigital
 
for n in range(9876, 9123, -1):
	p = str(n*1) + str(n*2)
		if is_pandigital(p): 
			print "Answer to PE38 = ", p
				break
