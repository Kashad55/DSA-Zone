// given N=number of animal
//  L= total numer of leg
// find numbers of animal X with 2 leg nd Y with 4 legs
// x+y=N  2x+4y=L
// y=(L-2N)/2  & x=N-Y

#include<iostream>
using namespace std;

int main(){

    int N=200;
    int L=540;
    int Y=(L-2*N)/2;
    int X=(N-Y);

    cout<<"number of anial wih 2 leg:"<<X<<" and 4 legs:"<<Y;

    return 0;
}