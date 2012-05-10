"""
 * The mathematics behind this problem are similar to the C solution but we are
 * instead creating a list of the Fibonacci numbers and using the native sum
 * function. This approach emphasizes keeping a running list of the Fibonacci
 * sequence which will take O(n) space compared to the C solution which takes
 * O(1) space. This implementation is slightly more pythonic, albeit less
 * efficient space wise.
"""

fibList = [0, 1]
while fibList[0] <= 4000000:
	fibList.insert(0, fibList[0] + fibList[1])
print sum([i for i in fibList if i % 2 == 0])
