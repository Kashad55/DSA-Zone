#include<vector>
#include<iostream>
using namespace std;

void printArray(vector<int>& arr, int n) {
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}
int main(){
    vector<int> arr = {5, 3, 8, 1, 10, 9};
    printArray(arr, 6);
    bubbleSort(arr, 6);
    cout<<"Array After Bubble Sort : "<<endl;
    printArray(arr, 6);

}