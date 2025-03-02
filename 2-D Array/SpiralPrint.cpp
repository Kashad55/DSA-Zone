#include<iostream>
#include<vector>
using namespace std;

    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        while(count < total) {
            
            //print starting row
            for(int index = startingCol; index<=endingCol && count < total; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; index<=endingRow && count < total; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; index>=startingCol && count < total; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; index>=startingRow && count < total; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        } 
        return ans;
    }
int main(){
    vector<vector<int> > arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector <int> ans = spiralOrder(arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}