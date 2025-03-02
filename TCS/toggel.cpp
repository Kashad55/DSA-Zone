// toogel bits n  umber and print number
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n0;
    int n=5;
    n0=n;

    string ans="";
    while(n>0){
        int i=n&1;
        if(i==0) ans='1'+ans;
        else ans='0'+ans;
        n=n>>1;
    }

    cout<<"\n binary number:"<<ans<<endl;
    int power=0;
    int res=0;
    for(int i=ans.length()-1;i>=0;i--){
        if(ans[i]=='1') res+=1*pow(2,power);
        power++;
    }


    cout<<"original:"<<n0<<" after toggeling:"<<res;

    return 0;
}
