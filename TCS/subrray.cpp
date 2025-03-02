#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans;

    cout<<"subarr"<<endl;
    int n=arr.size();
    for(int s=0;s<n;s++){
        for(int e=s;e<n;++e){
            vector<int>sub;
            for(int i=s;i<=e;i++){
                sub.push_back(arr[i]);
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            ans.push_back(sub);
        }
        
    }

    for(int s=0;s<n;s++){
        for(int e=s;e<n;e++){
            for(int i=s;s<=e;i++){
                cout<<arr[i];
            }
        }
    }

    cout<<endl;
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;

}