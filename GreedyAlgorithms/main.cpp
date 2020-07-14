//---------------------------------------------------------------
//Author: James Anthony Ortiz
//File: main.cpp
//Description: Finding the maximum profit-per-advertisement
//Greedy Optimization Problem.
//Compile: g++ -std=c++14 -O2 main.cpp -lm
//----------------------------------------------------------------



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Function: MaxAdRevenue(vector<long long>a, vector<long long>b)
//Parameters: vectors a, b
//a - The profit-per-click
//b - The average number of clicks per day
//Return: The total sum of both elements in vectors a & b.

long long int MaxAdRevenue(vector<long long> a, vector<long long> b)
{
    long long int sum =0;
    for(long long int i = 0; i < a.size(); i++)
    {
        sum  = sum + (a[i] * b[i]);
    }
    return sum;
}//End MaxAdRevenue():


//MAIN Driver Class:
int main() {


    vector<long long> a;
    vector<long long> b;

    int num_of_slots = 0;
    cin >> num_of_slots;

    int arr_size1 = num_of_slots;
    int arr_size2 = num_of_slots;

    int a_value;
    while(arr_size1 > 0)
    {
        cin >> a_value;
        a.push_back(a_value);
        arr_size1--;
    }

    int b_value;
    while(arr_size2 > 0)
    {
        cin >> b_value;
        b.push_back(b_value);
        arr_size2--;
    }

    //Sort both vectors a & b:
    std::sort(a.begin(), a.end(), greater<>());
    std::sort(b.begin(), b.end(), greater<>());

    //Display result of sum:
    std::cout << MaxAdRevenue(a, b) << " ";

   return 0;
}
