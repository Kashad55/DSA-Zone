#include <iostream>
using namespace std;
int i=1;
void f1(int n){
    if(i>3) return;
    cout<<"Kashad"<<endl;
    i++;
    f1(n);
}
void f2(int i, int n){     //as we r passing i, no need to use global variable(hence we saved memory)
    if(i>n){
        return;
    }
    cout<<"Kashad"<<endl;
    f2(i+1,n);
}
void f(int n){       //optimal
    if(n<=0) return;
    cout<<"Kashad"<<endl;
    f(n-1);
}
int main(){
    int n=3;
    f1(n);
    // f2(1,n);

return 0;
}