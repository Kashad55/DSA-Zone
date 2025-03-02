#include <iostream>
using namespace std;
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
public : 
    //Initialize the data member of ur ds
    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    // Enqueues 'X' into the queue.
    void push(int value){
        //to check whther queue is full
        if((front == 0 && rear == size-1) || rear == (front-1)%(size-1)){
            cout<<"Queue is full!"<<endl;
            return;
        }
        else if(front == -1){   //first element to push
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;   //to maintain cyclic nature
        }
        else{
            rear++;     //normal flow
        }
        arr[rear] = value;
        cout<<value<<" is pushed"<<endl;
    }
    // Dequeues 'X' from the queue.
    int pop(){
        if(front == -1){
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;     //marked as popped
        if(front == rear){   //only one element is present
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;      //to maintain cyclic nature
        }
        else{           //normal flow
            front++;
        }
        return ans;
    }
};
int main(){
    CircularQueue q(3);
    q.push(4);
    q.push(9);
    q.push(7);
    q.push(6);
    cout<<q.pop()<<endl;
    q.push(1);
    q.push(1);


return 0;
}