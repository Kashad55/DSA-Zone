//When all element are sorted in row as well as column wise
//and first element of each row need not to be larger than last element of prev row.
#include<iostream>
#include<vector>
using namespace std;
    bool BinSearch2(vector<vector<int> >& matrix, int key) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex < row && colIndex>=0 ) {
            int element = matrix[rowIndex][colIndex];
            
            if(element == key) {
                return 1;
            }
            
            if(element < key){
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
        }
        return 0;
    }
int main(){
    vector<vector<int> > arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    //vector<vector<int> > arr = {{1,2,3},{4,5,6},{7,8,9}};
    if(BinSearch2(arr,10)){
        cout<<"Element found!"<<endl;
    }
    else
        cout<<"Element Not found!"<<endl;
}