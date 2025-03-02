#include <iostream>
using namespace std;
int fib(int n){
    //Base Case
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n-1)+fib(n-2);
}
int main(){
    cout<<"3rd term in fibonacci series = "<<fib(3);

return 0;
}