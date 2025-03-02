//Important
#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        //If opening bracket, push in stack 
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        //else closing bracket, stacktop check and pop
        else{
            if(!st.empty()){
                char top = st.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s1 = "[()]{}{[()()]()}";     //balanced
    string s2 = "[[}[";    //Not balanced
    cout<<(isValid(s1) ? "Balanced" : "Not balanced")<<endl;
    cout<<(isValid(s2) ? "Balanced" : "Not balanced")<<endl;
return 0;
}