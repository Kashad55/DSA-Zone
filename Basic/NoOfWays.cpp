#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int count(int n) {
    vector<int> v(n+1, 0);
    v[0]=1;
    for(int i=3; i<n+1; i++) {
        v[i] = v[i] + v[i-3];
    }
    for(int i=5; i<n+1; i++) {
        v[i] = v[i] + v[i-5];
    }
    for(int i=10; i<n+1; i++) {
        v[i] = v[i] + v[i-10];
    }
    print(v);
    return v[n];
}

int main() {
    int n;
    cout << "Enter the number to count ways to represent as sum of 3, 5, and 10: ";
    cin >> n;
    cout << "Number of ways: " << count(n) << endl;
    return 0;
}


/*Consider a game where a player can score 3 or 5 or 10 points in a move. 
  Given a total score n, find number of distinct combinations to reach the given score.

Example 1:
Input
n = 10
Output
2
Explanation
There are two ways {5,5} and {10}.

Example 2:
Input
n = 20
Output
4
Explanation
There are four possible ways. {5,5,5,5}, {3,3,3,3,3,5}, {10,10}, {5,5,10}.*/