#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      
    // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);
      
      for(int i =0;i<n;i++) {
        temp[(i+k)%n] = nums[i];
      }
      
      for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
      }
    }
};
int main(){
    Solution obj;
    vector<int> arr = {1,5,7,8,10};
    obj.rotate(arr, 2);
}