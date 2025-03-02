#include<iostream>
using namespace std;

int main(){
    int n=2400;
    int ans=0;
    if(n%100!=0) ans=(n/100)+1;
    else ans=n/100;
    int year=n;

    if((year%4==0 && year%100!=0)|| year%400==0){
        cout<<"is leap";
    }
    else{
        cout<<"not leap";
    }

    cout<<"\nyear "<<n<<" belongs to "<<ans<<"century.";
    return 0;
}