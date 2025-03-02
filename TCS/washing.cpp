#include<bits\stdc++.h>
using namespace std;
int main(){
    int wt;
    cout<<"wt:";
    cin>>wt;

    if(wt<0) cout<<"invalid";
    else if(wt>7000) cout<<"overload";
    else{
        if(wt>=1 and wt<=2000) cout<<"25 min";
        else if(wt>=2000 and wt<=4000) cout<<"35 min";
        else cout<<"45 min";
    }

    return 0;
}