//
//Author: James Anthony Ortiz
//File: 123NumberFlip.cpp
//
/*Description:
You are given an integer n consisting of digits 1, 2, and 3 and you can flip one digit to a 3.
 Return the maximum number you can make.

 Ex. 
 Input:  n = 123
 Output: 323
 Explanation: We flip 1 to 3
*/

//A naive way to solve this problem would be converting the string to a char array, 
//then checking if the entire number would be greater than the original 
//value passed into the function if the element at i would be switched to 3. 
//This can be achieved in O(N) time complexity, and O(N) auxiliary space complexity.

using namespace std;

int solve(int n) 
{

    string num_to_str = to_string(n);
    int length = num_to_str.length();
    char arr[length + 1];
    strcpy(arr, num_to_str.c_str());
    
    int highest_num = n;
    char three = '3';
    
    //Go through the original length of the string:
    for(int i = 0; i < length; i++)
    {
        if(arr[i] != three)
        {
            //Temporarily conserve the elem at arr[i]:
            char ch_temp = arr[i];
            
            //Swap element in char arr:
            swap(arr[i], three);
            
            //check if the value is greater than original number,
            //if so, make it the highest value:
            int val = atoi(arr);
            if(val > highest_num)
            {
                highest_num = val;
            }
            
            //Return element back to place:
            swap(arr[i], ch_temp);
        }
        else
        {
            //If the current element is not a three:
            //Convert to an int, and check if the number is highest so far:
            int val = atoi(arr);
            
            if(val > highest_num)
            {
                highest_num = val;
            }
        }

    }
    
    //Return the highest value:
    return highest_num;
}

int main()
{
    int num = 323;
    int result = solve(num);
    cout << result;
    return 0;
}