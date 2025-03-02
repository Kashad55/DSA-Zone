#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x) {
    int c = 0;
    int s1 = 0, s2 = n - 1;
    int i = 0, j = n - 1;

    while (i < n && j >= 0) {
        int temp = mat1[i][s1] + mat2[j][s2];
        if (temp == x) {
            c++;
            s1++;
            s2--;
        } else if (temp > x) {
            s2--;
        } else {
            s1++;
        }
        if (s1 == n) {
            s1 = 0;
            i++;
        }
        if (s2 == -1) {
            s2 = n - 1;
            j--;
        }
    }
    return c;
}

int main() {
    // Sample matrices
    vector<vector<int>> mat1 = {{1, 5, 6},
                                {8, 10, 11},
                                {15, 16, 18}};

    vector<vector<int>> mat2 = {{2, 4, 7},
                                {9, 10, 12},
                                {13, 16, 20}};
    int n = 3; // Size of the matrices
    int x = 21; // Target sum

    // Function call
    int pairsCount = countPairs(mat1, mat2, n, x);

    // Output the result
    cout << "Number of pairs with sum " << x << ": " << pairsCount << endl;

    return 0;
}

