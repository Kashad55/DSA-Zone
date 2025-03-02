#include <iostream>
#include <deque>
using namespace std;

class Deque {
    int *arr;
    int front;
    int rear;
    int size;
    int currSize;

public: 
    // Initialize the data members of your Deque
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        currSize = 0;
    }

    // Pushes 'value' to the front of the Deque.
    void pushFront(int value) {
        if (currSize == size) {
            cout << "Deque is full!" << endl;
            return;
        } 
        if (currSize == 0) {  // First element to push
            front = rear = 0;
        } 
        else {
            front = (front - 1 + size) % size;
        }
        arr[front] = value;
        currSize++;
        cout << value << " is pushed at front" << endl;
    }

    // Pushes 'value' to the rear of the Deque.
    void pushRear(int value) {
        if (currSize == size) {
            cout << "Deque is full!" << endl;
            return;
        } 
        if (currSize == 0) {  // First element to push
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        currSize++;
        cout << value << " is pushed at rear" << endl;
    }

    // Pops the front element from the Deque.
    int popFront() {
        if (currSize == 0) {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        if (currSize == 1) {  // Only one element is present
            front = rear = -1;
        } 
        else {
            front = (front + 1) % size;
        }
        currSize--;
        return ans;
    }

    // Pops the rear element from the Deque.
    int popRear() {
        if (currSize == 0) {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        if (currSize == 1) {  // Only one element is present
            front = rear = -1;
        } 
        else {
            rear = (rear - 1 + size) % size;
        }
        currSize--;
        return ans;
    }

    // Returns the front element of the Deque.
    int getFront() {
        if (currSize == 0) {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Returns the rear element of the Deque.
    int getRear() {
        if (currSize == 0) {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Returns the current size of the Deque.
    int getSize() {
        return currSize;
    }
};

int main() {
    Deque dq(3);
    dq.pushFront(7);
    dq.pushFront(6);
    dq.pushRear(4); 
    dq.pushRear(9);
    
    cout << "Popped from front: " << dq.popFront() << endl;
    cout << "Popped from rear: " << dq.popRear() << endl;
    cout << "Front of deque: " << dq.getFront() << endl;
    cout << "Rear of deque: " << dq.getRear() << endl;
    cout << "Size of deque: " << dq.getSize() << endl;

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
*/    return 0;
}
