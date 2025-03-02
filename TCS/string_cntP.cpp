#include<iostream>
#include<map>
using namespace std;

int main(){
    string ip="abacdefeee";
    int p=2;
    map<char,int> mp;
    for(char i:ip){
        mp[i]++;
    }

    for(auto it:mp){
        if(it.second>=p){
            cout<<it.first<<" ";
        }
    }
    return 0;
}