#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxEnergy(int arr[], int n){
    // vector <int> a(arr,arr+size);
    // sort(a.begin(), a.end());
    
    sort(arr, arr+n);
    int res = arr[n-1] + arr[n-2];
    return res;
}

int main(){
    int arr[] = {9, -3, 8, -6, -7, 8, 10};
    cout<<"Maximum Energy is : "<<maxEnergy(arr,7)<<endl;
    //In c/c++ array, when we pass array as an arguments then its actually works on address of that resp element 
    //Not on actual array element. Hence we can't determine its size in called function.

    // int len = sizeof(arr)/sizeof(arr[0]);
    // int len=0;
    // for(int n : arr){
    //     len++;
    // }
    // cout<<"size : "<<len;
return 0;
}