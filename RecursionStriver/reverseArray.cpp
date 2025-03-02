#include <iostream>
using namespace std;
//reverse using s and e ptr
void fse(int arr[], int s, int e){
    if(s>=e) return;
    swap(arr[s], arr[e]);
    fse(arr, s+1, e-1);
}
//reverse using only i ptr
void fi(int arr[], int i, int n){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i]);
    fi(arr, i+1, n);
}
int main(){
    int arr[5] = {1,2,3,4,5};
    // fse(arr, 0, 5-1);
    fi(arr, 0, 5-1);
    for(int i=0; i<5; i++) cout<<arr[i]<<" ";
return 0;
}