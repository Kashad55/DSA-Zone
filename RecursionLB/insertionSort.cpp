#include <iostream>
using namespace std;
void insertionSort(int *arr, int i, int n){
    //Base case
    if(i == n) return;

    //Processing
    int j = i;
    while(j>0 && arr[j-1]>arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }
    for(int p=0; p<n; p++) cout<<arr[p]<<" ";
    cout<<endl;

    //Rec call
    insertionSort(arr, i+1, n);
}
int main(){
    int arr[5] = {4,6,0,3,1};
    int n = 5, i=0;
    insertionSort(arr,i, n);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

return 0;
}