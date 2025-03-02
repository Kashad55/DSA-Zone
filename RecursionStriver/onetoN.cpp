#include <iostream>
using namespace std;
void f(int i, int n){
    if(i>n) return;
    cout<<i<<" ";
    f(i+1, n);
}
void rev(int i, int n){
    if(n>i) return;
    cout<<i<<" ";
    rev(i-1, n);
}
void backTracking(int i, int n){   //no need n here, we can drop it
    if(i<1) return;
    backTracking(i-1, n);
    cout<<i<<" ";
}
void backRev(int i, int n){
    if(i>n) return;
    backRev(i+1, n);
    cout<<i<<" ";
}
int main(){
    int n=5;
    f(1,n);
    cout<<endl;
    rev(n, 1);
    cout<<endl;
    backTracking(n, n);
    cout<<endl;
    backRev(1, n);

return 0;
}