#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s = "Kashad";
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<"Reversed string : "<<ans;

return 0;
}