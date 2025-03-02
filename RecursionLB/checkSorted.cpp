#include <iostream>
using namespace std;
bool isSorted(int *arr, int size){      //When we pass array as an arguement, it actually pass address of first element of array
    //Base case
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remainingPart = isSorted(arr+1, size-1);
        return remainingPart;
    }
}
int main(){
    int arr[5] = {3,5,8,9,12};
    int size = 5;
    cout<<(isSorted(arr, size) ? "Sorted" : "Not sorted");

return 0;
}