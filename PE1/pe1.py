"""
 * The mathematics behind this problem is the same as the C solution but in
 * a much more concise, pythonic manner. The native sum() function is called
 * on a list comprehension over the range [0, 1000) only including numbers
 * that, mod 3 or 5 equal 0.
"""

print sum([i for i in range(1000) if i % 3 == 0 or i % 5 == 0])
