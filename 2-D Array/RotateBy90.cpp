#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& arr) {
    int row = arr.size();
    int col = arr[0].size();
    vector<vector<int>> a(row, vector<int>(col, 0));   //init of 2-d vector, Each element is initialized to 0.
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            a[i][j] = arr[j][i];    //Transform
        }
    }
    
    for(int i=0; i<row; i++){
        int s=0, e=col-1;
        while(s<=e){
            swap(a[i][s],a[i][e]);     //to rotate 90deg clockwise
            // swap(a[s][i],a[e][i]);  //to rotate 90deg anti-clockwise
            s++;
            e--;
        }
        // reverse(a[i].begin(), a[i].end());  //It'll also rotate clockwise
    }
    arr = a;
}
void rotateOpt(vector<vector<int>>& arr){
    int n= arr.size();
    int m = arr[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[j][n-1-i] = arr[i][j];      //to rotate 90deg clockwise
            // ans[n-1-j][i] = arr[i][j];         //to rotate 90deg anti-clockwise
        }
    }
    arr=ans;
}
void print(vector<vector<int>>& arr){
    int n= arr.size();
    int m = arr[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int> > arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > arr2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    print(arr);
    cout<<endl;
    rotateOpt(arr);
    print(arr);
}