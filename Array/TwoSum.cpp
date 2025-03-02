#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int num= nums[i];
        int sec = target-num;
        if(mp.find(sec) != mp.end()){
            return {mp[sec],i};
        }
        mp[num]=i;
    }
    return {-1,-1};
}

vector<int> twoSum2(vector<int>& nums, int target) {   //It requires sorted array if not then sort()
    int s=0, e=nums.size()-1;
    sort(nums.begin(), nums.end());
    while(s<e){
        int sum = nums[s]+nums[e];
        if(sum == target){
            return {s,e};
        }
        else if(sum < target) s++;
        else e--;
    }
    return {-1,-1};
}

int main(){
    vector<int> nums = {2, 6, 5, 8, 11};  
    int target = 14;
    vector<int> result = twoSum2(nums, target);

    cout << "Indices: " << result[0] << ", " << result[1] << endl;  // Expected output: Indices: 0, 1

    return 0;

return 0;
}