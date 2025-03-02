// blood relative number is sum of factoial of its digit is equal to its number
#include<iostream>
using namespace std;

int fact(int n){
    if(n==0 or n==1) return 1;
    else return n*fact(n-1);
}

int main(){
    // int n=145;
    int n=25;
    int o=n;
    // 1!+4!+5!=145
    int ans=0;
    while(n>0){
        int no=n%10;
        ans+=fact(no);
        n=n/10;
    }

    if(o==ans) cout<<"blood relative";
    else cout<<"not blood relative";


    return 0;
}