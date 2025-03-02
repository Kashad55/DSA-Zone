#include<iostream>
using namespace std;

void reverse(int arr[], int n) {

    int start = 0;
    int end = n-1;

    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr1[6] = {1,4,0,5,-2,15};   //even sized array
    int arr2[5] = {2,6,3,9,4};       //odd sized array

    reverse(arr1, 6);
    reverse(arr2, 5);

    printArray(arr1, 6);
    printArray(arr2, 5);


    return 0;
}