// count vowels,consonats,digit and special cmbol in string

#include<iostream>
using namespace std;

int main(){
    char ip[19]="geeks@123forgeeks#";
    int v,c,d,sp;
    v=c=d=sp=0;
    for(int i=0;i<19;i++){
        if(ip[i]>='0' && ip[i]<='9') d++;
        else if(ip[i]=='a' || ip[i]=='e' || ip[i]=='i' || ip[i]=='o' || ip[i]=='u') v++;
        else if('A'<ip[i]&& ip[i]<='Z' || 'a'<ip[i] && ip[i]<='z') c++;
        else sp++;
    }
    cout<<" vowels:"<<v<<" const:"<<c<<" digit:"<<d<<" special:"<<sp;
    return 0;
}