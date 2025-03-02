#include<vector>
#include<iostream>
using namespace std;

void printArray(vector<int>& arr, int n) {
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main(){
    vector<int> arr = {5, 3, 8, 1, 10, 9};
    printArray(arr, 6);
    cout<<"Array After Selection Sort : "<<endl;
    selectionSort(arr, 6);
    printArray(arr, 6);

}