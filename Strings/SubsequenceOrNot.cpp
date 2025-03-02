#include <iostream>
using namespace std;
bool isSubsequence(string s, string t) {
    int a = 0, b = s.length(), c = 0;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == s[a]) {
            a++;
            c++;
        }
    }
    return c == b;
}
int main(){
    cout<<(isSubsequence("abc", "ahbgdc") ? "s1 is Subsequence of s2" : "Not Subsequence")<<endl;
    cout<<(isSubsequence("axc", "ahbgdc") ? "s1 is Subsequence of s2" : "Not Subsequence")<<endl;

return 0;
}