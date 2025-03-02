#include<iostream>
#include<bits\stdc++.h>
#include<vector>
using namespace std;

bool isValid(int i, int j, int m,int n){
    if(i>=0 and i<m and j>=0 and j<n){
        return true;
    }
    return false;
}

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    int m=mat.size();
    int n=mat[0].size();
    vector<int>ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int curr=mat[i][j];

            int l,r,u,d;
            // left
            if(isValid(i,j-1,m,n)){
                l=mat[i][j-1];
            }
            else{
                l=INT_MIN;
            }

            // right
             if(isValid(i,j+1,m,n)){
                r=mat[i][j+1];
            }
            else{
                r=INT_MIN;
            }

            // up
             if(isValid(i+1,j,m,n)){
                u=mat[i+1][j];
            }
            else{
                u=INT_MIN;
            }
            // down
             if(isValid(i-1,j,m,n)){
                d=mat[i-1][j];
            }
            else{
                d=INT_MIN;
            }


            
            if(curr>=l and curr>=r and curr>=u and curr>=d){
                ans.push_back(curr);
            }
      }
    }

    cout<<"ans:";
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}