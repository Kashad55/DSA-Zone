#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";


    cout <<"int arr address (arr):"<< arr << endl;
    //attention here
    cout <<"char arr (ch):"<< ch << endl;
    cout <<"char arr address (ch):"<< &ch << endl;
    
    // char *c = ch;
    char *c = &ch[0];
    //prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;


    return 0;
}