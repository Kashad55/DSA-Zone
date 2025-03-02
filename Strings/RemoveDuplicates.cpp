#include <iostream>
#include <set>
#include <string>

using namespace std;

// Function to remove duplicate characters from a string
string removeDups(string str) {
    set<char> st;
    string s;
    for(char ch : str) {
        if(st.find(ch) == st.end()) { // Check if ch is not already in the set(== means ch is not present in the set)
            s += ch; // Add the character to the result string
        }
        st.insert(ch); // Mark this character as seen
    }
    return s;
}

int main() {
    // Sample input strings
    string input1 = "programming";
    string input2 = "aabbcc";
    string input3 = "abcabcabc";
    string input4 = "OpenAI";

    // Removing duplicates
    string result1 = removeDups(input1);
    string result2 = removeDups(input2);
    string result3 = removeDups(input3);
    string result4 = removeDups(input4);

    // Displaying results
    cout << "Original: " << input1 << " | Without duplicates: " << result1 << endl;
    cout << "Original: " << input2 << " | Without duplicates: " << result2 << endl;
    cout << "Original: " << input3 << " | Without duplicates: " << result3 << endl;
    cout << "Original: " << input4 << " | Without duplicates: " << result4 << endl;

    return 0;
}
