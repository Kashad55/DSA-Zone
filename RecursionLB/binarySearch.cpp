#include <iostream>
using namespace std;
void print(int arr[], int s, int e){
    for(int i=s; i<=e; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool binSearch(int arr[], int s, int e, int key){
    print(arr, s, e);
    //Base case
    if(s>e){        //element not found
        return false;
    }
    int mid = s + (e-s)/2;
    cout<<"Mid = "<<arr[mid]<<endl;
    if(arr[mid] == key){    //element found
        return true;
    }
    if(arr[mid] < key){
        return binSearch(arr, mid+1, e, key);
    }
    else{
        return binSearch(arr, s, mid-1, key);
    }
}
int binSearch2(int arr[], int s, int e, int key){
    //Base case
    if(s>e){        //element not found
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == key){    //element found
        return mid;
    }
    if(arr[mid] > key){
        return binSearch2(arr, s, mid-1, key);
    }
    else{
        return binSearch2(arr, mid+1, e, key);
    }
}
int main(){
    int arr[5] = {3,5,8,9,12};
    int size = 5;
    int start = 0, end = size-1;
    int key = 12;
    bool res = binSearch(arr, start, end, key);
    cout<<(res ? "***Found***" : "***Not found***")<<endl;
    int i = binSearch2(arr, start, end, key);
    cout<<"Element found at index = "<<i<<endl;

return 0;
}