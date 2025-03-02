/*Find substring that remains after the character ch has appeared count number of times.
Input: s = "Thisisdemostring", ch = 'i', count = 3
Output: ng
Explanation: The remaining substring of s after the 3rd
occurrence of 'i' is "ng", hence the output is ng.*/
#include <iostream>
using namespace std;
string printString(string s, char ch, int count) {
        // Your code goes here
        int c=0, i=0;
        string str="";
        for(i=0; i<s.size(); i++){
            if(s[i] == ch) c++;
            if(c == count){
                str = s.substr(++i, s.size()-i);          //string substr(start, length)
                break;
            } 
        }
        // while(i<s.size()){
        //     str+=s[++i];
        // }
        return str;
    }
int main(){
    

return 0;
}