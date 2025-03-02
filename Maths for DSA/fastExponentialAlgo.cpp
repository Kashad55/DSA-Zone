#include<iostream>
using namespace std;

int fastExpo(int a, int b ) {

    int res = 1;

    while(b > 0) {

        if(b&1) {
            //odd
            res = res*a;
        }
        b = b >> 1;     //same as : b=b/2
        a = a * a; 
    }
    return res;
}

int main() {

    int a,b;
    cout << "Enter the Values of a and b : ";
    cin >> a >> b;

    cout << "Answer is: " << fastExpo(a,b) << endl;

    return 0;
}