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
    //Optional (Just to clear unwanted data : Hence before deleting any node, make sure its next ptr is NULL)
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << val << endl;
    }
};
//insert at beginning of CLL(ie at head)
Node* insertAtHead(Node* head, int d){
    Node *newNode = new Node(d); 
    //empty list
    if(head == NULL){
        newNode->next = newNode;
        return newNode;    //Here head = newNode
    }
    else{
        //O(N) Approach
        // Node *curr = head;
        // while(curr->next != head){   //iterating till last node
        //     curr = curr->next;
        // }
        // curr->next = newNode;
        // newNode->next = head;
        // return newNode;

        //O(1) Approach
        newNode->next = head->next;
        head->next = newNode;
        swap(newNode->data, head->data);
        return head;
    }
}
Node* insertAtEnd(Node* head, int d){
    Node *newNode = new Node(d);
    //empty list
    if(head == NULL){
        newNode->next = newNode;
        return newNode;    //head = newNode
    }
    else{
        //O(N) Approach
        // Node *curr = head;
        // while(curr->next != head){   //iterating till last node
        //     curr = curr->next;
        // }
        // curr->next = newNode;
        // newNode->next = head;
        // return head;

        //O(1) Approach
        newNode->next = head->next;
        head->next = newNode;
        swap(newNode->data, head->data);
        return newNode;
    }
}
void print(Node* head){
    //empty list
    if(head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    Node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}
Node *deleteFromHead(Node *head){
    if(head == NULL) return NULL;   //empty list

    if(head->next == head){     //Only one node
        head->next = NULL;   //as written in destructor
        delete head;
        return NULL;
    }
    //O(N) Approach
    // Node *curr = head;
    // while(curr->next != head){  //iterating till last node
    //     curr = curr->next;
    // }
    // curr->next = head->next;
    // head->next = NULL;
    // delete head;
    // return curr->next;

    //O(1) Approach
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    temp->next = NULL;    //It is manadatory
    delete temp;
    return head;
}
Node *deleteFromEnd(Node *head){
    if(head == NULL) return NULL;   //empty list

    if(head->next == head){     //Only one node
        head->next = NULL;   //as written in destructor
        delete head;
        return NULL;
    }
    //O(N) Approach
    Node *prev = NULL;
    Node *curr = head;
    while(curr->next != head){  //iterating till last node
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;    //curr->next = head
    curr->next = NULL;
    delete curr;
    return head;

    //There is no O(1) Approach for deletion from end
}
void isPresent(Node *head, int d){
    Node *temp = head;
    do{
        if(temp->data == d){
            cout<<"Node with data = "<<d<<" is present!"<<endl;
            return;
        }
        temp = temp->next;
    }while(temp != head);
    cout<<"Node with data = "<<d<<" is NOT present!"<<endl;
}
void deleteNode(Node* &head, int value){
    if(head == NULL){   //empty list
        return;
    }
    if(head->next == head){     //Only one node
        head->next = NULL;   //as written in destructor
        delete head;
        return;
    }
    //Assuming that "value" is present in the Linked List
    Node *prev = NULL;
    Node *curr = head;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
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
    Node *head = NULL;
    head = insertAtHead(head, 1);
    print(head);
    head = insertAtEnd(head, 7);
    print(head);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    print(head);
    head = deleteFromEnd(head);
    print(head);
    head = deleteFromHead(head);
    print(head);
    deleteNode(head, 2);    //delete specific node
    print(head);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 6);
    print(head);
    isPresent(head, 5);
    cout<<(isCircular(head) ? "LL is Circular!" : "LL is not Circular!")<<endl;

return 0;
}