//===================================================================
//Author: James Anthony Ortiz
//File: gcd.cpp
//Description: An implementation of the euclidiean algorithm
//to solve for the GCD (Greatest Common Divisor) of two numbers
//Compile: g++ -std=c++14 -O2 gcd.cpp -lm
//===================================================================

#include <iostream>

using namespace std;

unsigned long long int euclid(unsigned long long int a, unsigned long long int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return euclid(b, a % b);
	}
	
}

//Main Driver Class:
int main(void)
{
	unsigned long long int x, y;
	
	std::cin >> x >> y;
	
	std::cout << euclid(x, y) << std::endl;
	
	return 0;
}