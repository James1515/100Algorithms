#
#Author: James Anthony Ortiz
#File: lastdigit.py
#Description: Finding the last digit in a fibonacci sequence 
#using modulus. 
#Compile: python lastdigit.py 
#

def lastdigitfib(n):
	a = 0
	b = 1
	c = 0
	for i in range(0, n):
		temp = a
		a = b 
		b = temp + b
		c = (a) % 10
	return c
	

#Main driver:
n = int(input())
print(lastdigitfib(n))