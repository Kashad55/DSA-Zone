#include <iostream>
#include <stack>
using namespace std;
//Normal Print
void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
//Using Recursion
void PrintStack(stack<int> st){
    //base case
    if(st.empty()){
        return;
    }
    //extract top of stack
    int num = st.top();

    //pop the top
    st.pop();

    //print the current top of stack ie. num
    cout<<num<<" ";

    //Proceed to print remaining stack
    PrintStack(st);

    //push the element back
    st.push(num);

}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    PrintStack(st);

return 0;
}