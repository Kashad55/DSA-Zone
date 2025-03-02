#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {6,1,8,0,3,0,1,5,3,0};
    int res=0;     //we can take array/vector as well
    string res2;
    // //Using set as a stl
    // set<int> st;
    // for(auto i : arr){
    //     if(st.find(i) == st.end()){
    //         // res = res*10 + i;
    //         res2 += to_string(i);
    //         st.insert(i);
    //     }
    // }
    //using vector as a stl
    vector<int> v;
    for(auto it : arr){
        if(find(v.begin(), v.end(), it) == v.end()){        //if(it is not present)
            res = res*10 + it;
            // res += to_string(i);
            v.push_back(it);
        }
    }
    cout<<res;
return 0;
}