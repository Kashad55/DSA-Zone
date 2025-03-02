#include<iostream>
using namespace std;

int main(){
    int n=538;
    int pro=1;
    int sum=0;
    while(n>0){
        int no=n%10;
        pro*=no;
        sum+=no;
        n=n/10;
    }
    cout<<"cost of product is:"<<abs(pro-sum);


    return 0;
}