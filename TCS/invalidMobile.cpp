#include<iostream>
using namespace std;
bool isvalid(string ip){
    if(ip.length()!=10){
        return false;
    }else{
        for(char c:ip){
            if(!isdigit(c)) return false;
        }
        return true;
    }
}

int main(){
    string ip;
    int cnt=0;
    while (true)
    {
        cin>>ip;
        if(ip=="q" || ip=="Q"){
            break;
        }   else{
            if(isvalid(ip)) cnt++;
        }
    }
    
    cout<<"valid num is:"<<cnt;

    return 0;
}