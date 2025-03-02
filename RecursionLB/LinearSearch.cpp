#include <iostream>
using namespace std;
void print(int arr[], int n){
    cout<<"Size of array = "<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool linSearch(int *arr, int size, int key){
    // print(arr, size);
    //Base case
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        return linSearch(arr+1, size-1, key);
    }
}
int main(){
    int arr[5] = {3,5,8,9,12};
    int size = 5;
    int key = 9;
    bool res = linSearch(arr, size, key);
    cout<<(res ? "***Found***" : "***Not found***");

return 0;
}