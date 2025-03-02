#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
//Brute Method  O(N3)
vector<vector<int>> ThreeSum(vector<int> &arr, int target){
    cout<<"Using Brute Method"<<endl;
    int n=arr.size();
    set<vector<int>> st;       //use 'set' bcoz it didnt store duplicate values
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] == target){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//Better Method  O(N2 * logN)
vector<vector<int>> ThreeSum2(vector<int> &arr, int target){
    cout<<"Using Better Method"<<endl;
    int n=arr.size();
    set<vector<int>> st;       //use 'set' bcoz it didnt store duplicate values
    for(int i=0; i<n; i++){
        set<int> hs;
        for(int j=i+1; j<n; j++){
            int third = target - (arr[i]+arr[j]);
            if(hs.find(third) != hs.end()){
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hs.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//Optimal Method  O(N2)   Sorted array is required
vector<vector<int>> ThreeSum3(vector<int> &arr, int target){
    cout<<"Using Optimal Method"<<endl;
    sort(arr.begin(), arr.end());
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum < target){
                j++;
            }
            else if(sum > target){
                k--;
            }
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;    //More Optimization(optional)
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 0, 3, 9, 1, -3, 5, 4, 8};
    int target = 5;
    cout<<"Triplets of sum = "<<target<<" are : "<<endl;
    vector<vector<int>> res = ThreeSum3(arr, target);
    int n=res.size();
    int m=res[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}