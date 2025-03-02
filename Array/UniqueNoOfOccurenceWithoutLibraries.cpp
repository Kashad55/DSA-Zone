#include <iostream>
using namespace std;

int unique(int a[], int n) {
    int b[1000] = {0}; // Initialize frequency array with all elements as 0

    // Count the frequency of each element in the array
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    // sorting
    for (int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++){
            if(b[i] > b[j]){
                int k = b[i];
                b[i] = b[j];
                b[j] = k;
            }
        }
    }
    for(int i = 0; i < n ; i++) {
        if(b[i] == b[i+1] && b[i]!=0){
            return false;
        }    
    }
    // Return true if unique freq are found
    return true;
}
int main(){
    int arr[6] = {1, 2, 2, 1, 1, 3};
    //int u = unique(arr, 7); 
    bool result = unique(arr, 6);
    cout << "Result: " << (result ? "true" : "false") << endl;

return 0;
}