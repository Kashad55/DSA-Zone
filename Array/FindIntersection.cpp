#include <iostream>
#include <vector>
using namespace std;

vector<int> Intersection(vector<int> arr1, int n, vector<int> arr2, int m) {
    vector<int> ans;
    
    for (int i = 0; i < n; i++) {
        int element = arr1[i];
        
        for (int j = 0; j < m; j++) {
            if (element == arr2[j]) {
                ans.push_back(element);
                arr2[j] = -1; // Mark the element as visited
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 5, 4};
    vector<int> b = {2, 5, 3, 9};
    vector<int> ans = Intersection(a, 6, b, 4);
    
    // Print the elements of the intersection
    cout << "Intersection: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
     
    return 0;
}
//This code has time complexity is O(n²)
//So we have to optimise it further