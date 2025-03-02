#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={0,1,2,3,0,4};
    int n=arr.size();
    vector<int>ans;
    for(auto i:arr){
        if(i!=0) ans.push_back(i);
        
    }
    while(n!=ans.size()){
        ans.push_back(0);
    }

    cout<<"ans:";
    for(auto t:ans){
        cout<<t<<" ";
    }

    return 0;
}