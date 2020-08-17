//
//Author: James Anthony Ortiz
//Problem: Two Number Sum
//Description: Write a function that takes a non empty array,
//of different integers.
//3 Attempts: With different optimizations
//




#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
//Time Complexity: O(n^2) Time
//Space Complexity: O(1) Space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
    // Write your code here.
    vector<int> n_vect;
    for(int i = 0; i < array.size(); i++){
        for(int j = 1; j < array.size(); j++){
            if((array[i] != array[j]) && (array[i] + array[j] == targetSum))
            {
                n_vect.push_back(array[i]);
                n_vect.push_back(array[j]);
                return n_vect;
            }
        }
    }

    return {};
}

//-----------------------------------------------------------------

#include <vector>
using namespace std;
//Time-Complexity: O(N) Time, O(N) Space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;
    for(int num: array){
        int potentialMatch = targetSum - num;
        if(nums.find(potentialMatch) != nums.end(){
            return vector<int>{potentialMatch, num};
        }else{
            nums.insert(num);
        }
    }

    return {};
}
*/

//---------------------------------------------------------------

#include <vector>
#include <algorithm>
using namespace std;
// O(n*log n) | O(1) Space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    int left = 0;
    int right = array.size() - 1;
    while(left < right){
        int currentSum = array[left] + array[right];
        if(currentSum == targetSum){
            return {array[left], array[right]};
        }else if(currentSum < targetSum){
            left++;
        }else if(currentSum > targetSum){
            right--;
        }
    }//end while
    return {};
}



int main() {
    vector<int> array{ 3, 5, 4, 8, 11, 1, -1, 6};
    int t_sum = 10;
    vector<int> n_arr = twoNumberSum(array, t_sum);
    cout << "[";
    for(int i: n_arr){
        cout << i << " ";
    }
    cout << "]";
    return 0;
}
