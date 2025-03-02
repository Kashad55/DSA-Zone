#include <iostream>
#include <queue>
using namespace std;
class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty(){
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){        //enqueue
        if(rear == size){
            cout<<"Queue is full!"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    int pop(){             //deueue
        if(qfront == rear){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int front(){
        if(qfront == rear){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};
int main(){
    Queue q(5);     //Queue initialization
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"front : "<<q.front();

    //All operations are same as below code

    /*//Creation of queue
    queue<int> q;
    q.push(11);
    cout<<"Front of q : "<<q.front()<<endl;
    q.push(12);
    q.push(13);
    cout<<"Front of q : "<<q.front()<<endl;

    cout<<"Size of q : "<<q.size()<<endl;
    q.pop();
    q.pop();
    // q.pop();
    cout<<"Size of q : "<<q.size()<<endl;
    
    if(q.empty()) cout<<"q is empty";
    else cout<<"q is not empty";*/
return 0;
}