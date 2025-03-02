#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int main(){
    int N=10;
    int K=3;
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int ans=INT8_MAX;

    for(int i=0;i<N;i++){
        if(i+K+1<N){
            vector<int>sub(arr.begin()+i,arr.begin()+i+K+1); //[4,5,6,7,8,9,10]
            int mi=*max_element(sub.begin(),sub.end());
            ans=min(ans,mi);
        }
        
    }

    cout<<ans;
    return 0;
}