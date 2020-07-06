//===================================================================
//Author: James Anthony Ortiz
//File: lcm.cpp
//Description: An implementation of the euclidiean algorithm
//to solve for the LCM (Least Common Multiple) of two numbers
//Compile: g++ -std=c++14 -O2 lcm.cpp -lm
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

unsigned long long int lcm(unsigned long long int a, unsigned long long int b)
{
	return a * (b / euclid(a, b));
}

//Main Driver Class:
int main(void)
{
	unsigned long long int x, y;
	
	std::cin >> x >> y;
	
	std::cout << lcm(x, y) << std::endl;
	
	return 0;
}