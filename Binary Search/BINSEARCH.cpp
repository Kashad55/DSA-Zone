#include <iostream>
using namespace std;
int BinSearch(int arr[], int n, int key){
    int s=0, e=n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            e = mid-1;
        else
            s = mid+1;
    }
    return -1;
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int BSRecursion(int arr[], int key, int s, int e){
    if(s>e) return -1;

    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        return BSRecursion(arr, key, s, mid-1);
    }
    else{
        return BSRecursion(arr, key, mid+1, e);
    }
}
int main(){
    int arr[5] = {1,3,6,8,10};    //arr must be sorted
    printArray(arr,5);
    // int k = BinSearch(arr, 5, 10);
    int s=0, e=5-1;
    int k = BSRecursion(arr, 10, s, e);
    cout<<k;

return 0;
}