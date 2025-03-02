#include <iostream>
using namespace std;
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    int currSize;
public : 
    //Initialize the data member of ur ds
    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        currSize = 0;
    }
    // Enqueues 'X' into the queue.
    void push(int value){
        //to check whther queue is full
        if(currSize == size){
            cout<<"Queue is full!"<<endl;
            return;
        }
        else if(currSize == 0){   //first element to push
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        currSize++;
        cout<<value<<" is pushed"<<endl;
    }
    // Dequeues 'X' from the queue.
    int pop(){
        if(currSize == 0){
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        if(currSize == 1){   //only one element is present
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
        currSize--;
        return ans;
    }
    int top(){
        if(currSize == 0){
            cout << "Queue is Empty " << endl;
            return -1;
        }
        return arr[front];
    }
    int qsize(){
        return currSize;
    }
};
int main(){
    CircularQueue q(3);
    q.push(4);
    q.push(9);
    q.push(7);
    q.push(6);
    cout<<"Popped : "<<q.pop()<<endl;
    cout<<"Top of q : "<<q.top()<<endl;
    // q.push(1);
    // q.push(1);
    cout<<"Size of q : "<<q.qsize();

return 0;
}