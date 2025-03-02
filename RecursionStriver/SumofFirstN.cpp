#include <iostream>
using namespace std;
//Parameterised recursion
void sumOfN(int n, int sum){    //here it contain sum as parameter
    if(n<1){
        cout<<sum<<endl;
        return;
    }
    sumOfN(n-1, sum+n);
}
//Functional Recursion
int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}
int fact(int n){
    if(n<=1) return 1;
    return n*fact(n-1);
}
int main(){
    int n=3;
    sumOfN(n, 0);
    cout<<sum(n)<<endl;
    cout<<fact(5);

return 0;
}