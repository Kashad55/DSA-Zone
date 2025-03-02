#include<bits/stdc++.h>
using namespace std;

int findPair(int n, int x, vector<int> &arr) {

    sort(arr.begin(), arr.end());
    
    // Initialize two pointers
    int left = 0, right = 1;

    // Traverse the array using two pointers
    while (right < n) {
        int diff = arr[right] - arr[left];
        
        if (diff == x) {
            return 1;
        } else if (diff < x) {
            // Move the right pointer to increase the difference
            right++;
        } else {
            // Move the left pointer to decrease the difference
            left++;
        }

        // Ensure that right pointer is always ahead of the left pointer
        if (right == left) {
            right++;
        }
    }
    // If no such pair is found, return -1
    return -1;
}

int findPair2(int n, int x, vector<int> &arr) {
    
    unordered_map<int,int>mp;
    for(auto it:arr){
        mp[it]++;
    }
    for(auto it:arr){
        if(mp.find(it+x)!=mp.end()){          //as our eq, num=it+x
            return 1;
        }
    }
    return -1;
}

int main() {

    int n = 6; // Size of the array
    int x = 78; // Target difference
    vector<int> arr = {5, 20, 3, 2, 5, 80}; // Example array

    int result = findPair2(n, x, arr);       //2nd soln is more optimize than 1st. Speed(map > binary search)
    if (result == 1) {
        cout << "A pair with difference " << x << " exists in the array." << endl;
    } else {
        cout << "No pair with difference " << x << " exists in the array." << endl;
    }

    return 0;
}
