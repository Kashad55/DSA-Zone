#include<iostream> 
using namespace std;

char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch + 'a' - 'A';
        return temp;
    }
}

bool checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(toLowerCase( a[s] ) != toLowerCase( a[e] ) )
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

void reverse(char name[], int n) {
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

int main( ) {

    char name[20];

    cout << "Enter your name :";
    // cin >> name;
    gets(name);          //take complete line i/p
    //name[2] = '\0';

    cout << "Your name is " << name << endl;;
    int len = getLength(name);
    cout << " Length: " << len << endl;

    reverse(name, len);
    cout << "Your reverse name is ";
    cout << name << endl;

    cout <<" Palindrome or Not: " << (checkPalindrome(name, len) ? "Yes" : "Not")<< endl;

    cout << " b in lwrcase is " << toLowerCase('b') << endl;
    cout << " A in lwrcase is " << toLowerCase('A') << endl;

    return 0;
}