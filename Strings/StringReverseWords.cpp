#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    int start = 0;
    int end = s.length();

    // Reverse individual words
    for (int i = 0; i <= end; i++) {
        if (s[i] == ' ' || i == end) {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    return s;
}
 
int main() {
    string str = "My name is Khan";
    cout << reverseWords(str);

    return 0;
}