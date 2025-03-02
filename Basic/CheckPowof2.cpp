#include <iostream>
#include<math.h>
using namespace std;
bool checkPow2(int n){
    for(int i=1; i<=n/2; i++){
        if(pow(2,i) == n){
            return true;
        }
    }
    return false;
}
int main()
{
    cout<<"Enter no. to check whether it is in power of 2 :";
    int n;
    cin>>n;
    cout<<(checkPow2(n) ? "Yes" : "No");

return 0;
}