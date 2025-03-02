#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int d){
        this->data = d;
        this->prev = NULL; 
        this->next = NULL;
    }
    //Optional (Just to clear unwanted data : Hence before deleting any node, make sure its next ptr is NULL)
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &tail, Node* &head, int d){
    //empty list
    if(head == NULL){
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(d);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail == NULL){
        Node *newNode = new Node(d);
        tail = newNode;
        head = newNode;
    }
    else{ 
        Node *newNode = new Node(d);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
    //insert at start
    if(pos == 1){
        return insertAtHead(tail, head, d);
    }
    Node *temp = head;
    while(pos-1 > 1){      //traverse till pos-1 node
        temp = temp->next;
        pos--;
    }
    //inserting at last/tail
    if(temp->next == NULL){
        return insertAtTail(tail, head, d);
    }
    //create new node for data d
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(int pos, Node* &head, Node* &tail){
    //deleting first or head node
    if(pos == 1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        while(pos > 1){     //traverse till deleting node
            prev = curr;
            curr = curr->next;
            pos--;
        }
        // //deleting middle OR last node
        if(curr->next == NULL){     //this is only to update tail ptr
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete curr;
    }
}
void sort(Node* &head){
    Node *temp1, *temp2;
    for(temp1=head ; temp1!=NULL ; temp1=temp1->next){
        for(temp2=temp1->next; temp2!=NULL ; temp2=temp2->next){
            if(temp1->data > temp2->data){
                swap(temp1->data, temp2->data);
            }
        }
    }
    cout<<"Linked list sorted successfully !"<<endl;
}
void reverse(Node* &head, Node* &tail){      //Node* &tail is added only to update tail ptr
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr != NULL){
        // next = curr->next;
        // curr->prev = next;
        // curr->next = prev;
        // prev = curr;
        // curr = next;
        swap(curr->prev, curr->next);
        curr = curr->prev;   //after swapping, prev becomes next
    }
    swap(head, tail);
}
int nodeCount(Node* &head){
    int c=0;
    Node* temp = head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    return c;
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    print(head);   //Currently there is no node, as we didnt initialize it in object.
    insertAtHead(tail, head, 10);
    print(head);
    insertAtTail(tail, head, 7);
    print(head);
    insertAtHead(tail, head, 5);
    print(head);
    insertAtTail(tail, head, 30);
    print(head);
    insertAtPosition(tail, head, 3, 15);
    print(head);
    deleteNode(1, head, tail);
    print(head);
    deleteNode(4, head, tail);
    print(head);
    deleteNode(2, head, tail);
    print(head);
    insertAtPosition(tail, head, 2, 9);
    print(head);
    cout<<"Node count = "<<nodeCount(head)<<endl;;
    sort(head);
    print(head);
    reverse(head, tail);
    print(head);
}