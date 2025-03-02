#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &arr, int s, int e){
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
}
void rotateByN(vector<int> &arr, int k){
    int s=0, e=arr.size()-1;
    reverse(arr, s, e);
    reverse(arr,s,k-1);
    reverse(arr,k,e);
}
int main(){
    vector<int> arr= {1,2,3,4,5};
    int k=2;
    rotateByN(arr, k);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}