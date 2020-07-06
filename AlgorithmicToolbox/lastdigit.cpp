//=================================================================
//Author: James Anthony Ortiz
//File: lastdigit.cpp
//Description: An optimal algorithm providing an O(n)
//solution to finding the last digit to the 
//fibonacci sequence.
//Compile: g++ -std=c++14 -O2 lastdigit.cpp -lm 
//==================================================================

//Include I/O Library:
#include<iostream>
#include<vector>

using namespace std;

//Naive Solution function:
int lastdigitfib(unsigned long long int n)
{
	//Declare variables:
	unsigned long long int a = 0, b = 1, temp;
	int c = 0;
	
	//iterate through fib numbers to n: O(n) asymptotic time 
	for(int i = 0; i < n; i++)
	{
		temp = a;
		a = b;
		b = temp + b;
		//Capture mod result to the last-digit of the fib sequence:
		c = (a) % 10;
	}
	
	//Return mod result with (1) memory space:
	return c;
}//end lastdigitfib()


//Improved Solution Function:
int fibonacci_sum_naive(long long n) {
	
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	
	for (long long i = 0; i <= 60; ++i) 
	{
		long long tmp_previous = previous;
		previous = current % 10;
		current = (tmp_previous + current) % 10;
		v.push_back(current);
	}
	
	return v[n%60];
}




//Main driver to program:
int main(void)
{
	//Create input variable:
	unsigned long long int input = 0;
	//Receive input from user:
	std::cin >> input;
	//Output the result:
	std::cout << fibonacci_sum_naive(input) << std::endl;
	return 0;
}