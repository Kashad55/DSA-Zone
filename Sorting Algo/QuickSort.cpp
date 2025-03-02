#include <iostream>
using namespace std;
//Love Babbar
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int c=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            c++;
        }
    }
    //place pivot at right position
    int pivotIdx = s+c;
    swap(arr[pivotIdx], arr[s]);

    //left and right wala part thik krdo
    int i=s, j=e;   //two pointer approach
    while(i < pivotIdx && j > pivotIdx){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIdx && j > pivotIdx){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIdx;
}
//Striver
int partition2(int arr[], int s, int e){
    int pivot = arr[s];
    int i=s;
    int j=e;   //j is the  partition index
    while(i < j){
        while(arr[i] <= pivot && i <= e-1){
            i++;
        }
        while(arr[j] > pivot && j>= s+1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[s], arr[j]);    //bcoz correct position of pivot is at j
    return j;    
}
void quickSort(int arr[], int s, int e){
    // base case
    if(s >= e){
        return;
    }
    //partition krdo
    int p = partition2(arr, s, e);

    quickSort(arr, s, p-1);      //left part sort krdo
    quickSort(arr, p+1, e);      //right part sort krdo
}
int main(){
    int n=5;
    int arr[n] = {3,1,5,2,4};

    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}