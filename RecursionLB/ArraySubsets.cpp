#include <iostream>
#include <vector>
using namespace std;
void subset(vector<int> nums, vector<int> output, int i, vector<vector<int>> &ans){
    //Base case
    if(i >= nums.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    subset(nums, output, i+1, ans);

    //include
    int element = nums[i];
    output.push_back(element);
    subset(nums, output, i+1, ans);
}
int main(){
    vector<int> nums = {1, 2, 3};
    vector<int> output;
    vector<vector<int>> ans;
    int i=0;
    subset(nums, output, i, ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}

/*Input: nums = [1,2,3]
  Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]*/