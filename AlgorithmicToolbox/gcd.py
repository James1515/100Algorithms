#
#Author: James Anthony Ortiz
#File: gcd.py
#Description: Finding the greatest common divisor (GCD)
#using Euclid's Algorithm and then going to a more optimal
#solution.
#Compile: python gcd.py


import sys 

def euclid(a, b):
	if b == 0:
		return a 
	else:
		return euclid(b, a % b)

#Driver Class:
x = int(input("Enter the first number: "))
y = int(input("Enter the second number: "))

print(euclid(x, y))
