#include <iostream>
#include <vector>
using namespace std;
//Love Babbar
void merge(int *arr, int s, int e){
    int mid=(s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    //creating temp array
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int k=s;   //k = main array index
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }
    k=mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    //merge 2-sorted array
    int i = 0;
    int j = 0;
    k=s;
    while(i<len1 && j<len2){
        if(first[i] < second[j]){
            arr[k++] = first[i++];
        }
        else{
            arr[k++] = second[j++];
        }
    }
    while(i<len1){
        arr[k++] = first[i++];
    }
    while(j<len2){
        arr[k++] = second[j++];
    }
    delete []first;
    delete []second;
}
//Striver
void merge2(int arr[], int s, int e){
    int mid = (s+e)/2;
    int i=s;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=e){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= e){
        temp.push_back(arr[j++]);
    }
    for(int i=s; i<=e; i++){
        arr[i] = temp[i-s];
    }
}
void mergeSort(int *arr, int s, int e){
    //base case (it stop the recursion)
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);   //left part
    mergeSort(arr, mid+1, e);  //right part
    merge2(arr, s, e);         //merge
}
int main(){
    int n=5;
    int arr[n] = {3,1,5,2,4};

    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}