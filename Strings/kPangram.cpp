#include <iostream>
using namespace std;
bool kPangram(string str, int k) {
    // code here
    int arr[26] = {0}, count=0, op=0;  //op = missing
    for(int i=0;i<str.length();i++){
        if(str[i] != ' '){
            arr[str[i]-'a']++;
            count++;
        }
    }    
    for(int i=0;i<26;i++){
        if(arr[i] == 0){
            op++;
        }
    }   
    return (k>=op) && (count >= 26);
}
int main(){
    string s1 = "the quick brown fox jumps over the lazy dog";  //k = 0    -->true
    string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaa";                   //k = 25   -->true
    string s3 = "a b c d e f g h i j k l m";                    //k = 20   -->false
    cout<<(kPangram(s3, 23) ? "Pangram" : "Not Pangram");

return 0;
}

/*Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.
      (A k-pangram extends this concept by allowing up to k letters to be missing from the sentence) 
Examples :
Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.

Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.

Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 13 alphabetic characters in this case, no amount of swapping can produce a panagram here.*/