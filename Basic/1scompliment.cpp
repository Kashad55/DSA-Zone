//LEETCODE QUE2
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter no:";
    cin>>n;
    int mask = 0;
    m=n;
    if(n==0){
        cout<<"1"<<endl;
    }
    while(m != 0){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;
    cout<<"Compliment of "<<n<<" = "<<ans;

//return 0;
}