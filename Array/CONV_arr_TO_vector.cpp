#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printVector(vector<int> arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[8] = {1,1,0,0,1,0,0,0};

    vector <int> vec(arr, arr+8);     //conv array into vector
    sort(vec.begin(), vec.end());     //sort vector  (#include <algorithm>)
    // printArray(vec,vec.size());
    printVector(vec, 8);

    int n = vec.size();
    // int arr2[n];
    // copy(vec.begin(), vec.end(), arr2);  //Copy vec into Array

    //Memory pointer pointing to the first element of array, size need not to be specified
    // int* arr2 = vec.data();     
    int* arr2 = &vec[0];
    printArray(arr2, n);

return 0;
}

// int main() {
//     // Vector
//     vector<int> vec = {1, 2, 3, 4, 5};

//     // Convert vector to array
//     int arr[vec.size()];
//     copy(vec.begin(), vec.end(), arr);

//     // Display array
//     cout << "Array: ";
//     for (int i = 0; i < vec.size(); ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }