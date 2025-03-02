#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    // vector<int> arr={2,4,2,4,2,4,2,4}; ={1,2,3,4,5,6,7};
    vector<int> arr;
    int n,v;
    cout<<"Enter size of an array = ";
    cin>>n;
    cout<<"Enter element : "<<endl;
    for(int i=0;i<n;i++){
        cin>>v; 
        arr.push_back(v);
    }
    // if(cin>>v ) cout<<"invalid inputs1"; return 0;
    map<int,int> freq;
    for(auto i:arr){
        freq[i]++;
    }
    // int n=arr.size();
    vector<int>ans;
    for(auto i:freq){
        if(i.second>=n/2){
            ans.push_back(i.first);
        }
    }
    if(ans.size()>0){
        cout<<"Majority Elements : "<<endl;
        for(auto i:ans) cout<<i<<" ";
    }
    else{
        cout<<"no majority element found!";
    }
    return 0;
}