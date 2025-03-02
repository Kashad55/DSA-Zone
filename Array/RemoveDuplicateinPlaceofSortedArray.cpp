//Remove duplicates element in place of sorted array, return the size of unique array
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
//Brute  TC : NlogN + N  | SC : O(N)
int removeDuplicates(int arr[], int n){
    set<int> st;      //if array is not sorted, use unordered_set
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    int i=0;
    for(auto it : st){
        arr[i++] = it;
    }
    return i;
}
//Optimal  TC : O(N)  |  SC : O(1)
int removeDuplicates2(int arr[], int n){
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}
int main(){
    int arr[9] = {1,1,2,2,2,3,3,3,3};
    cout<<"Initial array : ";
    print(arr,9);
    cout<<removeDuplicates2(arr, 9)<<endl;
    cout<<"After dupliactes removal array : ";
    print(arr,9);

return 0;
}