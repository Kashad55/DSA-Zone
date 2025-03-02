#include <iostream>
using namespace std;
char findTheDifference(string s, string t) {
    int charCount[26] = {0}; // Initialize an array to count character frequencies

    // Count character frequencies in string s
    for (char c : s) {
        charCount[c - 'a']++;
    }

    // Update character frequencies in string t
    for (char c : t) {
        charCount[c - 'a']--;
    }

    // Find the extra character in t
    for (int i = 0; i < 26; i++) {
        if (charCount[i] < 0) {
            return char('a' + i);
        }
    }



//ANOTHER METHOD----------------->>>
    /*char result = 0;

    for (char c : s) {
        result ^= c;
    }

    for (char c : t) {
        result ^= c;
    }

    return result;*/

}
int main(){
    cout<<"Extra Character : "<<findTheDifference("abcd", "abcde");

return 0;
}