#include <iostream>
using namespace std;
//ASCII A->Z = 65->92   |   a->z = 97->122
string decrypt(string s){
    string result;
    for(char ch : s){                             //let s[i] = a                  s[i] = y
        int decrypted = (ch - 'a' + 3) % 26;      //= 97-97+3 = 3%26 = 3          =121-97+3 = 27%26 = 1
        result += decrypted + 'a';                //3+97 = 100(d)                 =1+97 = 98(b)
    }
    return result;
}
int main(){
    string s = "yhqgz";
    cout<<"Incrypted string : "<<s<<endl;
    cout<<"Decrypted string : "<<decrypt(s);    
// cout<<21%26;
return 0;
}

/*Caesar cipher encryption is done by replacing a letter with 3 letters to left of it.
Example: a is replaced by x, d is replaced by a.
You would be given a encrypted cipher text, decrypt it and print the plaintext.`

Example 1: yhqgz
Output 1: bktjc

Example 2: abcde
Example 2: defgh*/