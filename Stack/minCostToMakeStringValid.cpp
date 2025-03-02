#include <iostream>
#include <stack>
using namespace std;
int minCost(string s){
    //odd condition
    if(s.length()%2 == 1){
        return -1;
    }
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        //if open brace
        if(ch == '{'){
            st.push(ch);
        }
        //else closed brace
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    //Stack contain invalid expression
    int a=0;   //count of open 
    int b=0;
    while(!st.empty()){
        if(st.top() == '{'){
            a++;
        }
        else{
            b++;
        }
        st.pop();
    }
    return (a+1)/2 + (b+1)/2;
}
int main(){
    string s1 = "{}}{}}";       //1
    string s2 = "{{{{";         //2 
    string s3 = "{{{}}";        //-1

    cout<<"Min cost to make string valid : "<<endl;
    cout<<s1<<": "<<minCost(s1)<<endl;
    cout<<s2<<": "<<minCost(s2)<<endl;
    cout<<s3<<": "<<minCost(s3)<<endl;

return 0;
}