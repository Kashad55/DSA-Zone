#include <iostream>
#include <stack>
using namespace std;
void printStack(stack<int> st){
    if(st.empty()) return;

    int num = st.top();
    st.pop();

    cout<<num<<" ";

    printStack(st);   //Recursive call

    st.push(num);
}
void insertAtBottom(stack<int> &st, int x){
    //Base Case
    if(st.empty()){
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, x);   //Recursive call

    st.push(num);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, num);
}
//Without recursion
void reverse(stack<int> &st){
    stack<int> st2;
    while(!st.empty()){
        st2.push(st.top());
        st.pop();
    }
    st = st2;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printStack(st); cout<<endl;
    reverseStack(st);
    // reverse(st);
    printStack(st);
return 0;
}