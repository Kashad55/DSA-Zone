#include<iostream>
using namespace std;

int main(){
    string ip="ThisIsAutomationEra";
    string ans="";
    for(char c:ip){
        if(isupper(c)){
            if(!ans.empty()) ans+=' ';
            ans+=tolower(c);
        }
        else  ans+=c;
    }

    cout<<ans;
    return 0;
}