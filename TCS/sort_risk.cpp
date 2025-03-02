#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>risk={0,1,3,2,0,1,2,1,3,0,1};
    sort(risk.begin(),risk.end());
    cout<<"risk after sort is:";
    for(auto i:risk){
        cout<<i<<" ";
    }


    return 0;
}