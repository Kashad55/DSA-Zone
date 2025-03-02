#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> MoveZeros(vector<int> nums) 
    {
        int nz = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[nz]);
                nz++;
            }
        }
       return nums;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {4,0,1,0,0,7};
    vector<int> res;
    res  = obj.MoveZeros(arr);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

}