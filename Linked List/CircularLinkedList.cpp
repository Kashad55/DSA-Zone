#include <bits/stdc++.h>
using namespace std;
class Node{
    public : 
    int data;
    Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << val << endl;
    }
};
void insertNode(Node* &head, int element, int d){
    //empty list
    if(head == NULL){
        Node *newNode = new Node(d);
        head = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        Node *curr = head;
        while(curr->data != element){
            curr = curr->next;
        }
        //element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node* &head){
    Node *temp = head;
    //empty list
    if(head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head != temp);
    cout<<endl;
}
void deleteNode(Node* &head, int value){
    //empty list
    if(head == NULL){
        cout << " List is empty, please check again!" << endl;
        return;
    }
    //non-empty list
    else{
        //assuming that "value" is present in the Linked List
        Node *prev = head;
        Node *curr = prev->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        //for only 1 node Linked List
        if(curr == prev){
            head = NULL;
        }
        //for >=2 nodes linked list
        if(head == curr){
            head = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
bool isCircular(Node *head){      // Better(O(N)  |  O(1))
    if(head == NULL) return true;

    Node *temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    } 
    return false;
}
bool isCircular2(Node *head){     // Brute (O(N)  |  O(N))
    map<Node*, bool> mp;
    Node *temp = head;
    while(temp != NULL){
        if(mp[temp] == true) {
            return true;
        }
        mp[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main(){
    Node *head = NULL;    //take head as well. we can take any(head or head)
    insertNode(head, 9, 3);   //for 1st node element value doesnt matter
    print(head);
    insertNode(head, 3, 5);
    print(head);
    insertNode(head, 5, 7);
    print(head);
    // insertNode(head, 2, 12);      //we cant add newNode at any previous unknown location
    // print(head);
    deleteNode(head, 5);
    print(head);
    cout<<(isCircular2(head) ? "LL is Circular!" : "LL is not Circular!")<<endl;

return 0;
}