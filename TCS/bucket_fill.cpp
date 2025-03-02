#include<bits\stdc++.h>
using namespace std;
int main(){

    //  id sum till cnt is 80% of bucket
    int b_c=100;
    int mup_c=20;
    int fill=0;
    int cnt=0;

    vector<int>capfill={20,20,20,20,20};
    for(int i=0;i<capfill.size();i++){
        fill+=capfill[i];
        cnt++;
        if(fill==80*b_c/100){
            cout<<cnt;
            break;
        }
    }
    return 0;
}