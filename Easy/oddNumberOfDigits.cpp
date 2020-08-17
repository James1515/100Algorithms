//
//Author: James Anthony Ortiz
//File: oddNumberOfDigits.cpp




/*
Description: Given a list of positive integers nums, return the number of integers that have odd number of digits.
Input:
nums = [1, 800, 2, 10, 3]

Output:
4
*/


/*
Approach:
Create a subroutine that determines if each digit of the integer array is odd,
then run the function linearly across all values in the array, 
keeping track of the odd values then returning these values back.

Time Complexity: O(N)
Auxiliary Space: O(1)

*/

#include <bits/c++std.h>

using namespace std;

//Subroutine Function:
//Function isOdd(int n)
//Params: n - number needed
//Return boolean answer
bool isOdd(int n){
    int counter = 0;
    while(n != 0){
        n/=10;
        counter++;
    }
    bool ans = (counter % 2 == 0)? false: true;
    return ans;
}

//Function: solve(int n)
//Params: nums - dynamic vector int array
//Returns int - number of odd values in the array
//Time Complexity O(N), auxiliary space O(1):
int solve(vector<int>& nums) {
    int num_of_odd_ints = 0;
    for(int i = 0; i < nums.size(); i++){
        if(isOdd(nums[i]) == true){
            num_of_odd_ints++;
        }
    }
    
    return num_of_odd_ints;
}