#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int SecurityKey(int a){
    vector<int> arr;
    int rem=0;
    while(a>0){
        rem = a%10;
        arr.push_back(rem);
        a = a/10;
    }
    sort(arr.begin(), arr.end());
    int f[10] = {0};         //freq of no. from 0-9
    for(int i=0; i<arr.size(); i++){
        f[arr[i]]++;
    }
    int c=0;
    for(int i=0; i<10; i++){
        if(f[i] >=2){
            c++;
        }
    }
    return c;
}
int main(){
    int data = 578378923;
    cout<<"Security Key : "<<SecurityKey(data);

return 0;
}