#include<iostream>
using namespace std;

int main(){
    string ip="999";
    int sum=0;
    for(int i=0;i<ip.length();i++){
        sum+=ip[i]-'0';
    }
    if(sum%3==0) cout<<"divi:"<<sum;
    else cout<<"not div";

    return 0;
}