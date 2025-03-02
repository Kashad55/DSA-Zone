#include <iostream>
using namespace std;

int unique(int a[], int n) {
    int b[10] = {0}; // Initialize frequency array with all elements as 0

    // Count the frequency of each element in the array
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    // Find the element with occurrence count 1
    for (int i = 0; i < n; i++) {
        if (b[a[i]] == 1) {
            return a[i];
        }
    }

    // Return -1 if no unique element is found
    return -1;
}
// int unique(int arr[], int size){
//     int ans=0;

//     for(int i=0; i<size; i++){
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }
int main() {
    int arr[7] = {5, 3, 7, 3, 5, 9, 7};
    int u = unique(arr, 7);

    if (u != -1) {
        cout << "Unique element is: " << u << endl;
    } else {
        cout << "No unique element found." << endl;
    }

    return 0;
}
