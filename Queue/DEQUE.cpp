#include <iostream>
#include <queue>
using namespace std;
class Deque{        //Doubly Ended Queue (Mainly used CPU Scheduling / Process Scheduling)
    int *arr;
    int front;
    int rear;
    int size;
public:
    //Initialize ur data structure
    Deque(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    void pushFront(int val){
        if(isFull()){
            cout<<"Deque is full"<<endl;
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = val;
    }
    void pushRear(int val){
        if(isFull()){
            cout<<"Deque is full"<<endl;
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;       //cyclic nature
        }
        else{
            rear++;
        }
        arr[rear] = val;
    }
    int popFront(){
        if(isEmpty()){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;        //marked as popped

        if(front == rear){      //single element is present
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;      //cyclic nature
        }
        else{
            front ++;
        }
        return ans;
    }
    int popRear(){
        if(isEmpty()){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;     //marked as popped

        if(front == rear){  // Only one element is present
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;     //cyclic nature
        }
        else{
            rear--;
        }
        return ans;
    }
    int getFront(){
        if(isEmpty()) return -1;
        return arr[front];
    }
    int getRear(){
        if(isEmpty()) return -1;
        return arr[rear];
    }
    bool isEmpty(){
        if(front == -1) return true;
        else return false;
    }
    bool isFull(){
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else return false;
    }
};
int main(){
    Deque d(5);
    d.pushFront(10);
    d.pushRear(50);
    d.pushRear(60);
    cout<<"front = "<<d.getFront()<<endl;
    cout<<"Back = "<<d.getRear()<<endl;

    cout<<"PopFront = "<<d.popFront()<<endl;
    cout<<"front = "<<d.getFront()<<endl;

    cout<<"PopRear = "<<d.popRear()<<endl;

    /*cout<<(-1)%1<<endl;
    deque<int> d;

    d.push_front(12);
    d.push_back(14);
    cout<<"Front = "<<d.front()<<endl;
    cout<<"Back = "<<d.back()<<endl;

    d.pop_front();
    cout<<"Front = "<<d.front()<<endl;
    cout<<"Back = "<<d.back()<<endl;

    d.pop_back();
    cout<<"Front = "<<d.front()<<endl;
    cout<<"Back = "<<d.back()<<endl;

    if(d.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
*/
return 0;
}