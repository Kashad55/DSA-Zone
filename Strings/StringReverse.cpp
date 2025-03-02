#include <iostream>
#include <algorithm>
using namespace std;

string reverseWord(string str){
    int s=0,  e=str.length() -1;
    while(s<=e){
        swap(str[s++], str[e--]);
    }
    // reverse(str.begin(), str.end());    //Built-in function
    return str;
}
int main(){
    string str = "LeetCode Geeks";
    cout<<reverseWord(str);

return 0;
}