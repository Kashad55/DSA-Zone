#include<iostream>
#include<vector>
using namespace std;
vector<int> wavePrint(vector<vector<int> > arr, int row, int col)
{
    vector<int> ans;
    
    for(int i=0; i<col; i++) {
        
        if( i & 1 ) {
            //odd Index -> Bottom to top
            
            for(int j = row-1; j>=0; j--) {
                ans.push_back(arr[j][i]);
            }    
        }
        else
        {
            // 0 or even iondex -> top to bottom
            for(int j = 0; j<row; j++) {
                ans.push_back(arr[j][i]); 
            }
        }   
    }
    return ans;
}
int main(){
    vector<vector<int> > arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector <int> ans = wavePrint(arr, 3,3);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}