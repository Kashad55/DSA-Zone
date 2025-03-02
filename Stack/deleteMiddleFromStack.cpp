#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &st, int count, int size){
    //base case
    if(count == size/2){
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    //Recursive call
    solve(st, count+1, size);

    //add the popped num
    st.push(num);
}
void printStack(stack<int> st){
    if(st.empty()) return;

    int num = st.top();
    st.pop();

    cout<<num<<" ";

    printStack(st);     //Recursive call

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
    int size = st.size();
    int count=0;
    solve(st, count, size); cout<<endl;
    printStack(st);

return 0;
}