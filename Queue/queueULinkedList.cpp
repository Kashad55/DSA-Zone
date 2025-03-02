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
class Queue{
    public:
    Node *front = NULL;
    Node *rear = NULL;
    int size = 0;

    void push(int value){
        Node *newNode = new Node(value);
        if(front == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void pop(){
        if(front == NULL){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    int top(){
        if(front == NULL){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return front->data;
    }
    int qsize(){
        return size;
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(6);
    q.push(2);
    q.push(8);
    cout<<"Top : "<<q.top()<<endl;
    cout<<"Size : "<<q.qsize()<<endl;
    q.pop();
    cout<<"Top : "<<q.top()<<endl;
    cout<<"Size : "<<q.qsize()<<endl;

return 0;
}