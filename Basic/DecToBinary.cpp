#include<iostream>
#include<math.h>
using namespace std;
int main(){
    // cout<<"Enter no.:";
    int n=16;
    // cin>>n;
    int ans=0, i=0, b=n;
    while(n != 0){
        int bit = n & 1;
        ans = bit * pow(10, i) + ans;   //pow() is inbuilt fx of math.h
        n = n >> 1;     //Shift n to right by 1 place
        i++;
    }
    cout<<"Binary of "<<b<<" = "<<ans<<endl;
}