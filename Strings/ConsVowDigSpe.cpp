#include <iostream>
#include <string>
using namespace std;
int main() {
    string S;
    cout<<"Enter a string : ";
    getline(cin, S);
    int vowel = 0, consonant = 0, digit = 0, special = 0;
    string vowels = "aeiou";
    string digits = "0123456789";
    string specials = "@#$%!*&^";

    for (char i : S) {
        if (vowels.find(i) != -1) {
            vowel++;
        } 
        else if (digits.find(i) != -1) {
            digit++;
        } 
        else if (specials.find(i) != -1) {
            special++;
        } 
        else {
            consonant++;
        }
    }
    cout <<"Vowel = "<< vowel << ", Consonants =  " << consonant << ", Digit = " << digit << ", Special Char = " << special << endl;
    return 0;
}