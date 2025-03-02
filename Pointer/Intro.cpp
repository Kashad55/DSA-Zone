#include <iostream>
using namespace std;

int main(){
    int a=10;
    int *p = &a;
    int **q= &p;
    double d = 20;
    double *dptr = &d;
    //copying a pointer
    double *ptr = dptr;
    cout<<"Value of a :"<<*p<<endl;
    cout<<"Value of a using ** :"<<**q<<endl;
    cout<<"Address of a :"<<p<<endl;
    p++;
    cout<<"Address of a after p++ :"<<p<<endl;
    cout<<"Value of * to * :"<<*ptr<<endl;
    cout<<"Size of *p :"<<sizeof(*p)<<endl;
    cout<<"Size of p :"<<sizeof(p)<<endl;

    //important concept
    int i = 3;
    int *t = &i;
    cout <<"Value of i :"<<*t << endl;
    *t = *t +1;
    cout <<"Value of i or *t after *t = *t +1 :"<< *t << endl;
    cout << "before t :" << t << endl;
    t = t + 1;
    cout << "after t=t+1 :" << t << endl;


return 0;
}