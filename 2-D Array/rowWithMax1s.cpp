#include <iostream>
#include <vector>
using namespace std;

// Function to find the row with the maximum number of 1s in ANY 2-d array
int rowWithMax1s(vector<vector<int>> arr) {
    int maxi = 0;
    int rowIndex = -1;
    for(int i = 0; i < arr.size(); i++) {
        int c = 0;
        for(int j = 0; j < arr[0].size(); j++) {
            if(arr[i][j] == 1) c++;
        }
        if(c > maxi) {
            maxi = c;
            rowIndex = i;
        }
    }
    return rowIndex;
}
//If each row is SORTED in increasing order 
int rowWithMax1(vector<vector<int>> arr) {    //traverse col wise and if 1 if found return rowIndex
    for(int i = 0; i < arr[0].size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[j][i] == 1) return j;
        }
    }
    return -1;
}

int main() {
    // Sample 2D vector (matrix)
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    // Finding the row index with the maximum number of 1s
    int rowIndex = rowWithMax1(arr);

    // Displaying the result
    if(rowIndex != -1) {
        cout << "The row with the maximum number of 1s is: " << rowIndex << endl;
    } else {
        cout << "There are no 1s in the matrix." << endl;
    }

    return 0;
}
