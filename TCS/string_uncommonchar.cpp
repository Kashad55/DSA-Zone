#include<iostream>
#include<set>
using namespace std;

int main(){
    set<char>s1;
    // string ip="tiger";
    // string ip2="ti";
    string ip="processed";
    string ip2="esd";
    for(char c:ip2){
        s1.insert(c);
    }
    string ans="";
    for(char c: ip){
        if(s1.find(c)==s1.end()) ans+=c;
    }
    cout<<ans;

    return 0;
}