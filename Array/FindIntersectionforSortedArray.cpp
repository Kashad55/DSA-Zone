#include <iostream>
#include <vector>
using namespace std;

vector<int> Intersection(vector<int> arr1, int n, vector<int> arr2, int m) {
    
    vector<int> ans;
    int i=0, j=0;

    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else
            j++;
    }

    return ans;  
}

int main() {
    vector<int> a = {1, 2, 2, 3, 6, 7};
    vector<int> b = {2, 5, 6, 9};
    vector<int> ans = Intersection(a, 6, b, 4);
    
    // Print the elements of the intersection
    cout << "Intersection: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
     
    return 0;
}