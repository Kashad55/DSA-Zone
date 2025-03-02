#include <iostream>
using namespace std;
void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1 < size){
            int k= arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = k;
        }
    }
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int even[8] = {4,7,3,8,6,1,2,9};
    int odd[5] = {54,67,32,78,21};

    cout<<"Given Array : "<<endl;
    printArray(even, 8);
    swapAlternate(even, 8);
    cout<<"\nAfter swapping alternate element in array : "<<endl;
    printArray(even, 8);

return 0;
}