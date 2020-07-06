#
#Author: James Anthony Ortiz
#File: fibonacci.py
#Description: An optimal solution to the fibonacci sequence 
#in python 3.
#

def fibonacci(n):
    a = 0
    b = 1
    for i in range(0, n):
        temp = a
        a = b
        b = temp + b
    return a

# Driver Program 
n = int(input()) 
print(fibonacci(n)) 


