#include<iostream>
using namespace std;
int main(){
    
    int s=2,e=5;
    int sum=0;
    for(int i=s;i<=e;i++){
        sum+=(i*i*i);
    }
    cout<<"\n sum from range:"<<s<<" n "<<e<<" is :"<<sum;
    return 0;
}