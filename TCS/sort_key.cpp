#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    // string ip="apple";
    // string key="eapl";
    string ip="welcome";
    string key="lcomwe";
    unordered_map<char,int> mp;
    for(auto ch:ip){
        mp[ch]++;
    }

    string ans="";

    for(char c:key){
        if(mp.find(c)!=mp.end()){
            while(mp[c]>0){
                ans+=c;
                mp[c]--;
            }
        }
    }

    cout<<ans;


    return 0;
}