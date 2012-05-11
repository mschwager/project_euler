"""
 * Similar to the C solution this simply iterates over the whole problem space
 * checking if the product is a palindrome. Instead of checking integers this
 * solution converts the product to a string and checks lexographically because
 * this is so easily done in Python. Convert to a string using the native str()
 * function then check if that equals str[::-1] which is the string in reverse.
 * If the string equals its reversal we know it's a palindrome.
"""

print max([i*j for i in range(100,1000) for j in range(i, 1000) if str(i*j) == str(i*j)[::-1]])
