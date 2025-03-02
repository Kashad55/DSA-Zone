#include <iostream>
using namespace std;
int addWoArith(int a, int b){
    for(int i=1; i<=b; i++){
        a++;
    }
    return a;
}
int addWoOperator(int x, int y){
    //Iterate till there is no carry
    while(y!=0){
        unsigned carry = x & y;     //deal wt -ve no's(contain common set bits of x and y)
cout<<carry<<" ";
        x = x ^ y;      //Sum of bits of x & y where atleast one of the bits is not set
cout<<x<<" ";
        y = carry << 1;     //Carry is left shifted by 1 to get required sum
cout<<y<<endl;
    }
    return x;
}
int main(){
    int a=31, b=10;
    // cout<<addWoArith(a,b)<<endl;
    cout<<addWoOperator(a,b)<<endl;

return 0;
}