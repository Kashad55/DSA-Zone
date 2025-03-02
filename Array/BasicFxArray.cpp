#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[8] = {1,3,5,0,2,9,3,7};
    printArray(arr, 8);
    int n=8;
    swap(arr[0], arr[n-1]);        //Swapping of arr element (#include <iostream>)
    printArray(arr, 8);
    sort(arr, arr + n);            //Sorting of arr element (#include <algorithm>)
    printArray(arr, 8);

    //Size of array :
    cout<<sizeof(arr) / sizeof(arr[0]);     //=> 32 / 4 = 8

return 0;
}