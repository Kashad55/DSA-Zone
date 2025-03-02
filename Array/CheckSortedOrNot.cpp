#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isMonotonic(vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            decreasing = false;
        } 
        else if (nums[i] < nums[i - 1]) {
            increasing = false;
        }

        if (!increasing && !decreasing) {
            return false;
        }
    }
    return true;
}
bool checkSorted(vector<int> arr){
    for(int i=1; i<arr.size(); i++){
        if(arr[i] >= arr[i-1]){         //In INCREASING ORDER
        // if(arr[i] <= arr[i-1]){      //In DECREASING ORDER

        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr1 = {1,3,5,5,8};    //asc
    vector<int> arr2 = {8,6,3,2};    //desc
    vector<int> arr3 = {3,0,1,8};    //random array
    cout<<"arr1 = "<<(isMonotonic(arr1) ? "Monotonic" : "false")<<endl;
    cout<<"arr2 = "<<(isMonotonic(arr2) ? "Monotonic" : "false")<<endl;
    cout<<"arr3 = "<<(isMonotonic(arr3) ? "Monotonic" : "false")<<endl;

    cout<<"<---Sorted or not--->"<<endl;
    cout<<"arr1 = "<<(checkSorted(arr1) ? "Sorted" : "false")<<endl;
    cout<<"arr2 = "<<(checkSorted(arr2) ? "Sorted" : "false")<<endl;

return 0;
}