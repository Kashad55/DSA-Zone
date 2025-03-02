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
//Same as printStack
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
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printStack(st);
    insertAtBottom(st, 15);
    cout<<endl;
    printStack(st);

return 0;
}