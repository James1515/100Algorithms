//============================================================
//Author: James Anthony Ortiz
//File: fibonacci.cpp
//Description: Application of the fibonacci sequence 
//using an optimal solution O(n)
//Compile: g++ -pipe -02 -std=c++14 fibonacci.cpp -lm
//============================================================

//Include Standard IO Library:

#include <iostream>
unsigned long long fibonacci(unsigned long long int n)
{
	unsigned long long int a, b;
	a = 0;
	b = 1;
	unsigned long long int temp;
	for(int i = 0; i < n; i++)
	{
		temp = a;
		a = b;
		b = temp + b;
	}
	
	return a;
	
}// end fibonacci()

//Main driver class:
int main(void)
{
	
	int input = 0;
	//Enter input:
	std::cin >> input;
	
	/*
	std::cout << "Fib Sequence  |  Fib Number: " << std::endl;
	
	for(int i = 1; i <= input; i++)
	{
		std::cout << "   " << i << "    " << fibonacci(i) << std::endl;
	}
	*/
	
	//Display result to desktop:
	std::cout << fibonacci(input) << std::endl;
	
	return 0;
//END main 
}