#include <vector>
#include <iostream>
using namespace std;

int maxLen(vector<int> &arr) {
    int maxi=0;
    int n=arr.size();
    for(int i=0;i <n; i++){
        for(int j=i; j<n; j++){
            vector<int> v(arr.begin()+i, arr.begin()+j+1);
            int c0=0, c1=0;
            for(int num: v){
                if(num==0) c0++;
                else c1++;
            }
            if(c0 == c1){
                int len=v.size();
                maxi = max(len, maxi);
            }
        }
    }
    return maxi;
}
int main(){
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};
    cout<<"Result = "<<maxLen(arr);

return 0;
}

/*
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
*/