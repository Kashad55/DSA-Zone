#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int kLargest(int arr[], int n, int k){
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    auto it = st.end();
    while(k--){
        it--;
    }
    return *it;
}
int kSmallest(int arr[], int n, int k){
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    auto it = st.begin();
    k=k-1;   //0-based indexing
    while(k--){
        it++;
    }
    return *it;
}
//When arr is given in form of vector
int kthSmallest(vector<int> &arr, int k) {
    k=k-1;
    while(k--){
        int m = *min_element(arr.begin(), arr.end());
        arr.erase(find(arr.begin(), arr.end(), m));
    }
    //OR
    // while(k--){
    //     arr.erase(min_element(arr.begin(), arr.end()));
    // }
    return *min_element(arr.begin(), arr.end());
}
int main(){
    int arr[8] = {5,3,0,3,2,6,9,6};   //0 2 3 3 5 6 6 9
    int n=8, k=3;
    cout<<k<<"th Largest = "<<kLargest(arr,n,k)<<endl;
    cout<<k<<"th Smallest = "<<kSmallest(arr,n,k)<<endl;

    vector<int> v = {1,6,5,4,2,3,0};
    cout<<k<<"th Smallest from vector = "<<kthSmallest(v,k)<<endl;
return 0;
}