//======================================================================
//Author: James Anthony Ortiz
//File: inversions.cpp
//Description: Number Of Inversions problem
//Time Complexity: O(n log n) with MergeSort / Space complexity: O(N) Auxiliary Array
//Compile: g++ -std=c++14 -O2 inversions.cpp -lm
//=======================================================================

#include <bits/stdc++.h>
using namespace std;

long long int mergeSort(long long int arr[], long long int temp[], long long int left, long long int right);
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right);

/* This function sorts the input array and returns the
number of inversions in the array */
int mergeSort(long long int arr[], long long int array_size)
{
    long long int temp[array_size];
    return mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
long long int mergeSort(long long int arr[], long long int temp[], long long int left, long long int right)
{
    long long int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This function merges two sorted arrays
and returns inversion count in the arrays.*/
long long int merge(long long int arr[], long long int temp[], long long int left,
          long long int mid, long long int right)
{
    long long int i, j, k;
    long long int inv_count = 0;

    i = left; /* i is index for left subarray */
    j = mid; /* j is index for right subarray */
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            //The inversion count value is itself plus the mid value + i:
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
        (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
        (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /* Copy back the merged elements to original array */
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    //Return the subroutine control with inversion count:
    return inv_count;
}

// MAIN Driver Class:
int main() {

    //Used for accepting input from the user:
    long long int input;
    cin >> input;

    long long int num_values = input;
    long long int arr[input];

    //Holds value from input:
    long long int value;
    //For-loop to fill long long int array:
    for(long long int i = 0; i < input; i++)
    {
        cin >> value;
        arr[i] = value;
    }

    //Obtain Number of Inversions from MergeSort Algorithm:
    long long int ans = mergeSort(arr, num_values);

    //Display Result:
    cout << ans;

    return 0;
}//END MAIN