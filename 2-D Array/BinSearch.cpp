//When all element of row are sorted and first element of each row is larger than last element of prev row. 
#include<iostream>
#include<vector>
using namespace std;
    bool BinSearch(vector<vector<int> >& matrix, int key) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        
        while(start<=end) {
            
            int mid = start + (end-start)/2;
            int element = matrix[mid/col][mid%col];
            
            if(element == key) {
                return 1;
            }
            
            if(element < key) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return 0;
    }
int main(){
    vector<vector<int> > arr = {{1,2,3},{4,5,6},{7,8,9}};
    if(BinSearch(arr,7)){
        cout<<"Element found!"<<endl;
    }
    else
        cout<<"Element Not found!"<<endl;
}