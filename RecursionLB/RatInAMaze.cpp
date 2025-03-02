#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m){
    if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    else{
        return false;
    }
}
void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
    //Base case
    //You've reach {x,y} here
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;  //mark visited

    //4=choices  D|L|R|U
    //Down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();    //Remove path after each move
    }
    //Left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();    //Remove path after each move
    }
    //Right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();    //Remove path after each move
    }
    //Up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();    //Remove path after each move
    }

    visited[x][y] = 0;      //remove visited flag while Backtracking
}
int main(){
    vector<vector<int>> m = {{1,0,0,0},
                             {1,1,0,1},
                             {1,1,0,0},
                             {0,1,1,1}};
    vector<string> ans;
    int x = 0;  //Source index {0,0}
    int y = 0;
    int row = m.size();
    int col = m[0].size();   //m is an n*n array
    int n = row;
    vector<vector<int>> visited(row, vector<int>(col,0));   //Initialize m size vector with 0
    string path = "";
    solve(m, n, ans, x, y, visited, path);
    sort(ans.begin(), ans.end());

    for(auto s: ans){
        cout<<s<<endl;
    }


return 0;
}