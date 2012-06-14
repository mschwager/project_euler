"""
 * In python we can use the native sum() function on two simple list
 * comprehensions to get the desired results
"""

print sum([i for i in range(1,101)])**2 - sum([i**2 for i in range(1,101)])
