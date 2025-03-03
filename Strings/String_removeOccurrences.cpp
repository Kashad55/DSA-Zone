// #include<string>
#include<iostream>
using namespace std;

string removeOccurrences(string s, string part) {
    
    while(s.length()!=0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

main(){
    string s = "daabcbaabcbc", part = "abc";        // o/p=> dab
    cout<<removeOccurrences(s,part);
}