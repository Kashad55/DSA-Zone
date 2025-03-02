#include <iostream>
using namespace std;
void bubbleSort(int *arr, int n){
    //Base case
    if(n == 1) return;

    //Processing
    for(int j=0; j<n-1; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }

    //Rec call
    bubbleSort(arr, n-1);
}
int main(){
    int arr[5] = {4,6,0,3,1};
    int n = 5;
    bubbleSort(arr, n);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

return 0;
}