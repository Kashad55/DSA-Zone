#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    map<int,int> freq;
    vector<int> vec={1,1,2,3,2};
    int n=vec.size();

    for(int i=0;i<n;i++){
        freq[vec[i]]++;
    }
    for(auto ip:freq){
        if(ip.second%2==0) cout<<ip.first<<" ";
    }

    return 0;
}