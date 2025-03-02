#include <iostream>
using namespace std;
void selectionSort(int *arr, int i, int n){
    //Base case
    if(i == n) return;

    //Processing
    int minIndex = i;
    for(int j=i+1; j<n; j++){
        if(arr[minIndex] > arr[j]){
            minIndex = j;
        }
    }
    swap(arr[i], arr[minIndex]);
    for(int p=0; p<n; p++) cout<<arr[p]<<" ";
    cout<<endl;

    //Rec call
    selectionSort(arr, i+1, n);
}
int main(){
    int arr[5] = {4,6,0,3,1};
    int n = 5, i=0;
    selectionSort(arr,i, n);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

return 0;
}