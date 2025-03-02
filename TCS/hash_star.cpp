#include<iostream>
#include<map>
using namespace std;

int main(){
    string ip="###*******#";
    map<char,int> mp;
    for(auto c:ip){
        mp[c]++;
    }
    cout<<mp['*']-mp['#'];


    return 0;
}