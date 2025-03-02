#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int>& arr, int n) {
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j;
        for(j=i-1; j>=0; j--) {
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
}
void insertionSort2(int n, vector<int> &arr){
    for(int i=0; i<n; i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}
int main(){
    vector<int> arr = {7, 3, 5, 9, 1, 4};
    printArray(arr, 6);
    insertionSort(6, arr);
    cout<<"Array After Insertion Sort : "<<endl;
    printArray(arr, 6);

return 0;
}