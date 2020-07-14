//
//Author: James Anthony ortiz
//File: main.cpp
//Description: Implementation of BinarySearch,
//used to search for keys from a particular array from input.
//Compile: g++ -std=c++11 -O2 -Wall main.cpp -lm
#include <bits/stdc++.h>

using namespace std;

//Function: Binary Search Iterative
//Params:
//arr    - Vector of long long int values
//l      - lowest INDEX of the Array
//h      - highest INDEX of the array
//key    - the value that is being looked for
//Returns: long long int - Index location
long long int BinarySearch(std::vector<long long> &arr, long long l, long long h, long long int key){
    while (l <= h) {
        int m = std::floor(l + (h - l) / 2);

        // Check if x is present at mid
        if (arr[m] == key)
            return m;

        // If x greater, ignore left half
        if (arr[m] < key)
            l = m + 1;

            // If x is smaller, ignore right half
        else
            h = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
} //end function BinarySearch()




//MAIN Driver Class:
int main()
{
    /* Test Code:
    //Sample Vector Array:
    vector<long long int> A = {1, 2, 5, 7, 9, 10, 150};

    //call to BinarySearch:
    cout << BinarySearch(A, 0, A.size() - 1, 150) << endl;
     */

    long long int num_values;
    vector<long long> arr;
    cin >> num_values;

    long long int input; //Used for input in while-loop
    while(num_values > 0){
        cin >> input;
        arr.push_back(input);
        num_values--;
    }

    //Recieve input for the # of Keys to Search For:
    long long int num_key_comparisons;
    cin >> num_key_comparisons;

    //Create vector of Keys:
    vector<long long> arr_keys;
    //Used for input in while-loop:
    long long int key_input;
    while(num_key_comparisons > 0){
        cin >> key_input;
        arr_keys.push_back(key_input);
        num_key_comparisons--;
    }

    //--------------------------------------

    //Go through keys, and display results:
    for(long long arr_key : arr_keys)
    {
        cout << BinarySearch(arr, 0, arr.size() - 1, arr_key) << " ";
    }

    return 0;
}//End MAIN
