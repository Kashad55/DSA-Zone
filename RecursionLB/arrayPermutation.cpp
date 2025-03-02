#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> nums, vector<vector<int>> &ans, int i){
    //Base case
    if(i >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=i; j<nums.size(); j++){
        swap(nums[i], nums[j]);
        solve(nums, ans, i+1);
        swap(nums[i], nums[j]);     //Backtrack (So that modifications in array after 1st swapping will be neutralized)
    }
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    int i = 0 ;
    solve(nums, ans, i);

    for(auto v : ans){
        for(int i : v){
            cout << i << " ";
        }
        cout<<endl;
    }

return 0;
}

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/