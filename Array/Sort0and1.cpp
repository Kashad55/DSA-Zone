#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void sortOne(int arr[], int n) {

    int left = 0, right = n-1;
    while(left < right) {

        if(arr[left] == 0){ 
            left++; 
        }
        else if(arr[right] == 1){
            right--;
        }
        //agar yha pohoch gye ho, iska matlab 
        //arr[left]==1 and arr[right]==0 
        else 
            swap(arr[left], arr[right]);
        
    }
}
// void sortOne(int arr[], int n){
//     // sort(ans, ans + n);          //sorting an array
// }
int main(){
    int arr[8] = {1,1,0,0,1,0,0,0};
    // sortOne(arr, 8);
    // printArray(arr, 8);
    cout<<sizeof(arr) / sizeof(arr[0]);     //=> 32 / 4 = 8
return 0;
}