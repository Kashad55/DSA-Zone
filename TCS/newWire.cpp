#include<bits\stdc++.h>
using namespace std;
int main(){
    // int n;
    // cin>>n;
    vector<int> arr={7,6,8,6,1,1};

    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto i:arr){
        pq.push(i);
    }

    int ans=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=0;
        if(!pq.empty()){
            second=pq.top();
            pq.pop();
        }
        ans+=(first+second);
        pq.push(first+second);
    }
    cout<<ans;
    return 0;
}