#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class Stack{
    public : 
    Node *top = NULL;
    int size = 0;

    void push(int value){
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    void pop(){
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int peek(){
        return top->data;
    }
    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        else return false;
    }
    int stackSize(){
        return size;
    }
};
int main(){
    Stack st;
    cout<<(st.isEmpty() ? "Empty" : "Not empty")<<endl;
    st.push(1);
    st.push(6);
    st.push(2);
    st.push(5);
    cout<<"Top : "<<st.peek()<<endl;
    cout<<"Size : "<<st.stackSize()<<endl;
    st.pop();
    cout<<"Top : "<<st.peek()<<endl;
    cout<<"Size : "<<st.stackSize()<<endl;

return 0;
}