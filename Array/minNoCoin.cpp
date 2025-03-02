#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[9]={1,2,5,10,20,50,100,500,1000};
    int amt = 13;      //Rs.13
    int e=9-1;
    int sum=0, c=0;
    int b=amt;
    while(sum!=b && e>=0){
        int coin = arr[e];
        if(coin <= amt){
            sum+=coin;
            amt-=coin;
            c++;
        }
        else{
            e--;
        } 
    }
    cout<<"Min coins required = "<<c;
    return 0;
}