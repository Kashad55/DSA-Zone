#include <iostream>
#include <stack>
using namespace std;
class Stack{
    //properties
    public : 
    int *arr;
    int top;
    int size;

    //behavior
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    //Operations
    void push(int data){
        if(top < size-1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack OverFlow!"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack UnderFlow!"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else return false;
    }
    int stsize(){
        return top+1;
    }
};
int main(){
    Stack st(5);

    st.push(22);
    st.push(32);
    st.push(45);
    st.push(87);
    st.push(65);
    st.push(55);

    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }
//All the operations are done in O(1)

    /*//Creation of Stack
    stack<int> st;

    //push operation
    st.push(10);
    st.push(20);

    //Pop operation
    st.pop();

    cout<<"Printing top element : "<<st.top()<<endl;

    if(st.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    cout<<"Size of the stack is : "<<st.size();*/

return 0;
}