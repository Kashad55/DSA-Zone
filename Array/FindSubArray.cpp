/*Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that 
adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. 
In case no such subarray exists return an array consisting of element -1.

Example 1:
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

Example 2:
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int i = 0, j = 0;
        long long sum = 0;
        bool present = false;
        while(j < n)
        {
            sum = sum + arr[j];
            if(sum > s)
            {
                while(sum > s)
                {
                    sum = sum - arr[i];
                    i++;
                }
            }
            if(sum == s && sum != 0)
            {
                present = true;
                break;
            }
            j++;
        }
        if(present == true)
            return {i+1,j+1};
        return {-1};
    }
int main(){
    vector<int> arr1 = {1,2,3,7,5};
    vector<int> arr2 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> res = subarraySum(arr2, 10, 15);
    cout<<res[0]<<" "<<res[1];

return 0;
}