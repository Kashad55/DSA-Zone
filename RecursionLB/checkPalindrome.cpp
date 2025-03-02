#include <iostream>
using namespace std;
bool isPalindrome5(string &str, int s, int e){
    //Base case
    if(s>e){
        return true;
    }
    if(str[s] != str[e]){
        return false;
    }
    //Rec call
    else{
        return isPalindrome5(str, s+1, e-1);
    }
}
//Using one ptr
bool isPalindrome(string &str, int e){
    if(e < str.length()/2) return true;
    
    int s = str.length()-e-1;
    if(str[s] != str[e]){
        return false;
    }
    else{
        return isPalindrome(str, e-1);
    }
}
int main(){
    string str = "nayan";
    // bool res = isPalindrome(str, 0, str.length()-1);
    bool res2 = isPalindrome(str, str.length()-1);
    cout<<(res2 ? "Palindrome" : "Not palindrome");

return 0;
}