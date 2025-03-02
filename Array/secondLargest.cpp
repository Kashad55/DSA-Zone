#include <iostream>
#include <vector>
using namespace std;
//Brute  O(2N)
int secondLargest(vector<int>arr){
    int n=arr.size();
    int l=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > l) l=arr[i];
    }
    int sl=-1;
    for(int i=0; i<n; i++){
        if(arr[i] > sl && arr[i]!=l)
            sl=arr[i];
    }
    return sl;
}
//Optimal   O(N)
int secondLargest2(vector<int>arr){
    int n=arr.size();
    int l=arr[0], sl=INT16_MIN;
    for(int i=1; i<n; i++){
        if(arr[i] > l){
            sl=l;
            l=arr[i];
        }
        else if(arr[i] > sl && arr[i] < l){
            sl = arr[i];
        }
    }
    return sl;
}
//Optimal for second smallest
int secondSmallest(vector<int>arr){
    int n=arr.size();
    int s=arr[0], scs=INT16_MAX;
    for(int i=1; i<n; i++){
        if(arr[i] < s){
            scs=s;
            s=arr[i];
        }
        else if(arr[i] > s && arr[i] < scs){
            scs = arr[i];
        }
    }
    return scs;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    cout<<"Second largest = "<<secondLargest2(arr)<<endl;
    cout<<"Second smallest = "<<secondSmallest(arr);

return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     string s;
//     getline(cin,s);
//     reverse(s.begin(), s.end());
//     cout<<s<<endl;
// }

// #include <iostream>
// using namespace std;

// int main(){
//     // int r = 1 + (rand() % 99);
//     int r =rand();
//     cout<<r;

// return 0;
// }
