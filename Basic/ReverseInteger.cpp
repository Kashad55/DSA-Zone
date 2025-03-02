//LEETCODE QUE
#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,x;
    cout<<"Enter no.:";
    cin>>n;
    int ans=0; 
    // //When reverse of no. is goes beyond integer range:
    // if(ans>INT_MAX/10 || ans<INT_MIN/10){
    //     return 0;
    // }
    x=n;
    while(x != 0){
        int digit = x % 10;
        ans = ans*10 + digit;
        x /= 10;
    }
    cout<<n<<" in reverse order :"<<ans;

return 0;
}