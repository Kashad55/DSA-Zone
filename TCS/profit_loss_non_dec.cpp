#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // vector<int> arr={2,3,1,4,5,-9,8};
    vector<int> arr={1,-9,8};
    int sum=0;
    for(int i:arr){
        sum+=i;
    }
    if(sum>0){
        cout<<"possible \n";
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        cout<<"seq is:";
        for(int i:arr){
            cout<<i<<" ";
        }


    } 
    else cout<<"immposible\n ";
}