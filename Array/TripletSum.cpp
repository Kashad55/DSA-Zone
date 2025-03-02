#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// The provided findTriplets function

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first element of the triplet
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int start = i + 1;
        int end = n - 1;

        while (start < end) {
            int currsum = arr[i] + arr[start] + arr[end];

            if (currsum == K) {
                vector<int> temp = {arr[i], arr[start], arr[end]};
                ans.push_back(temp);
                start++;
                end--;

                // Skip duplicates for the second and third element
                while (start < end && arr[start] == arr[start - 1]) {
                    start++;
                }
                while (start < end && arr[end] == arr[end + 1]) {
                    end--;
                }
            } else if (currsum < K) {
                start++;
            } else {
                end--;
            }
        }
    }

    return ans;
}

// Function to display the output
void displayTriplets(const vector<vector<int>>& triplets) {
    cout << "Output:" << endl;
    if (triplets.empty()) {
        cout << "No triplets found." << endl;
    } else {
        for (const vector<int>& triplet : triplets) {
            for (int num : triplet) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int K;
    cout << "Enter the target sum (K): ";
    cin >> K;

    vector<vector<int>> triplets = findTriplets(arr, n, K);

    // Displaying the output
    displayTriplets(triplets);

    return 0;
}
