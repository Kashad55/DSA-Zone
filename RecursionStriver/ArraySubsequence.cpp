#include <iostream>
#include <vector>
using namespace std;
void printSS(int i, vector<int> &ds, int arr[], int n){
    if(i == n){
        for(auto it : ds) {
            cout<<it<<" ";   //printing is done while backtracking
        } 
        if(ds.size() == 0) cout<<"{}";
        cout<<endl;
        return;
    }
    //pick the particular index into the subsequence
    ds.push_back(arr[i]);
    printSS(i+1, ds, arr, n);
    ds.pop_back();
    
    //This calls/ condn can be reverse
    //not picked or not take condn, this elemement is not added to ur subsequence
    printSS(i+1, ds, arr, n);
}
int main(){
    int arr[] = {3, 1, 2};
    vector<int> ds;
    int n=3, i=0;
    printSS(i, ds, arr, n);
return 0;
}