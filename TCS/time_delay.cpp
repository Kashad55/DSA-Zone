#include<iostream>
using namespace std;

int main(){
    // int h=8; //h
    // int m=45; //m
    // int h1=9; //h
    // int m1=00; //min
    // int x=1; //hour

    int h=1; //h
    int m=30; //m
    int h1=12; //h
    int m1=30; //min
    int x=4; //hour

    int cur_min=h*60+m;
    int next_min=h1*60+m1;

    int delay_min=x*60;

    int delay_timr=delay_min+cur_min;

    int delay=(delay_timr-next_min);
    if(delay>0)  cout<<"delayed time is"<<delay<<" min";
    else cout<<"delayed time is "<<540+delay<<" min";


    return 0;
}