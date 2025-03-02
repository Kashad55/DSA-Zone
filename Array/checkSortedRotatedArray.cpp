#include <iostream>
#include <vector>
using namespace std;class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i] < nums[i-1])
                cnt++;
        }
        if(nums[nums.size()-1] > nums[0])
            cnt++;
        
        return cnt<=1;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {8,10,2,5,6};
    bool res  = obj.check(arr);
    if(res) cout<<"Yes! It is Sorted Rotated array"<<endl;
    else cout<<"No! It is not a Sorted Rotated array"<<endl;
}