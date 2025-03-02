#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j] && arr1[i]!=0){
            arr3[k++] = arr1[i++];
            // k++;
            // i++;
        }
        else{
            arr3[k++] = arr2[j++]; 
            // k++;
            // j++;
        }
    }
    while(i<n){
        arr3[k++] = arr1[i++];
        // k++;
        // i++;
    }
    while(j<m){
        arr3[k++] = arr2[j++];
        // k++;
        // j++;
    }

}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr1[6] = {1,2,3,0,0,0};
    int arr2[3] = {2,5,6};
    int arr[6] = {0};       //it is good to init arr with 0

    merge(arr1, 5, arr2, 3, arr);
    printArray(arr,6);

return 0;
}