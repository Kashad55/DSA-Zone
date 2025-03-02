#include<iostream>
#include<math.h>
using namespace std;
int main(){
    cout<<"Enter binary no.:";
    int a;
    cin>>a;
    int ans=0, i=0;
    int n=a;
    while(n != 0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2, i);
        }
        n = n / 10;   //it'll left shift ex.(123/10 = 12)
        i++;
    }  
    cout<<a<<" to decimal is "<<ans;   
}