#include <iostream>
#include <stack>
using namespace std;
bool checkRedundant(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        //Ya to ')' hai or lowercase letter
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main(){
    string s1 = "(a*b+(c/d))";       //No redundancy
    string s2 = "((a/b))";           //one redundent () found   
    cout<<(checkRedundant(s1) ? "Found" : "Not Found")<<endl;
    cout<<(checkRedundant(s2) ? "Found" : "Not Found")<<endl;
return 0;
}