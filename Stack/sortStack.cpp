#include <iostream>
#include <vector>
#include <algorithm>
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
//Brute
void sortStackBrute(stack<int> &st){
    vector<int> arr;
    while(!st.empty()){
        arr.push_back(st.top());
        st.pop();
    }
    sort(arr.begin(), arr.end());
    for(int i : arr){
        st.push(i);
    }
}
//Optimal (recursion)
void sortedInsert(stack<int> &st, int num){
    //base case
    if(st.empty() || (!st.empty() && st.top() < num)){
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();

    //rec call
    sortedInsert(st, num);

    st.push(n);
}
void sortStack(stack<int> &st){
    //Base case
    if(st.empty()){
        return;
    }
    int num = st.top();
    st.pop();
    //Recursive call
    sortStack(st);

    sortedInsert(st, num);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(-2);
    st.push(3);
    st.push(-4);
    st.push(5);
    printStack(st); cout<<endl;
    // sortStackBrute(st);
    sortStack(st);
    printStack(st);
return 0;
}