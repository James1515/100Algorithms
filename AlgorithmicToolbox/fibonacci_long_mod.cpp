//=================================================================
//Author: James Anthony Ortiz
//File: fibonacci_long_mod.cpp
//Description: 
//An algorithm that uses the Pisano method to calculate 
//a very large Fn modulo m value of the Fibonacci sequence.
//Compile: g++ -std=c++14 -O2 fibonacci_long_mod.cpp -lm 
//=================================================================



#include <iostream>
using namespace std;

long long get_fibonacci_huge_mod(long long n, long long m) {
    long long result;
    long long index;
    long long period = n+1;
    long long sz = min (n+1,m*m+1); // Bound for period
    long long *F = new long long[sz];
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;

    for (long long i = 3; i < sz; i++)
	{
      F[i] = (F[i-2] + F[i-1]) % m;
	  
      if (F[i] == 1 && F[i-1] == 0)
	  { // we have returned back to where we started
        period = i-1;
        break;
      }
    }

    index = n % period;
    result = F[index];
    delete[]F;
    return result;

}

int main(void)
{
	long long int input, mod;
	cin >> input >> mod; 
	cout << get_fibonacci_huge_mod(input, mod) << endl;
	return 0;
	
}