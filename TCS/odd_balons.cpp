#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    vector<char> b={'r','r','c','c','b','b','b','p','p','p','p','p'};
    unordered_map<char,int> mp;
    for(auto i:b){
        mp[i]++;
    }
    for(auto it:b){
        if(mp[it]%2!=0){
            cout<<"ball:"<<it;
            break;
        } 
        
    }
    return 0;
}