#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //Optional (Just to clear unwanted data : Hence before deleting any node, make sure its next ptr is NULL)
    ~Node(){
        int val = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }
};

void insertAtHead(Node* &head, int d){
    //new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void print(Node* &head){
    if(head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
    //Insert as start/head
    if(pos == 1){
        return insertAtHead(head, d);
    }
    Node *temp = head;
    // while(pos > 2){           //while(pos-1 > 1)
    //     temp = temp->next;
    //     pos--;
    // }
    int cnt = 1;

    while(cnt < pos-1) {
        temp = temp->next;
        cnt++;
    }
    //insert at last/tail
    if(temp->next == NULL){
        return insertAtTail(tail, d);
    }
    //Creating a node for data d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteNode(int pos, Node* &head, Node* &tail){
    //deleting first/head node
    if(pos == 1){
        Node *temp = head;
        head = head->next;
        //free the memory of start node
        temp->next = NULL;     //bcoz we dont want deleting node pointing to any node of our LL, hence NULL it. as its code written in destructor
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node *curr = head;
        Node *prev = NULL;

        while(pos > 1){        //traverse till deleting node
            prev = curr;
            curr = curr->next;
            pos--;
        }
        // deleting middle OR last/tail node 
        if(curr->next == NULL){     //this is only to update tail ptr
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int nodeCount(Node* &head){
    int c=0;            //bcoz for last node, temp->next=NULL
    Node *temp = head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    return c;
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
Node* reverse(Node* &head){      //TC:O(N), SC:O(1)
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;   //bcoz after loop terminates, curr=NULL;
    return head;   
}
//Here head as well as tail are properly updated
Node* reverseUpdateTail(Node* &head, Node* &tail){      //Node* &tail is added only to update tail ptr
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    swap(head, tail);
    return head;
}

void reverserec(Node* &head){
    // Base case: If head is null or only one node
    if (head == NULL || head->next == NULL) {
        return;
    }
    // Recursive call to reverse the rest(forward) of the list
    Node* forward = head->next;
    reverserec(forward);
    

    head->next->next = head;
    head->next = NULL;

    head = forward;
}
//Love babbar style
void revrec(Node* &head, Node* curr, Node *prev){
    //Base case
    if(curr == NULL){
        head = prev;
        return;
    }
    revrec(head, curr->next, curr);
    curr->next = prev;
}
Node *reverseRec(Node* &head){
    Node *curr = head;
    Node *prev = NULL;
    revrec(head, curr, prev);
    return head;
}
//Brute
Node* getMiddle(Node* &head){
    int len = nodeCount(head);
    int mid = len/2;
    Node* temp = head;
    while(mid>0){
        temp = temp->next;
        mid--;
    }
    return temp;
}
//Optimal approach
Node* getMiddle2(Node* &head){   
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
void printOddEven(Node* &head){
    Node* temp = head;
    cout<<"\nOdd Nodes : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        if(temp!=NULL){
            temp = temp->next;
        }
    }
    cout<<"\nEven Nodes : ";
    temp = head->next;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        if(temp!=NULL){
            temp = temp->next;
        }
    }
    cout<<endl;
}
//Brute(HERE WE ADDING ODD NODE TO VECTOR AND THEN EVEN NODES, AFTER THAT VALUES INSIDE NODES ARE OVERRIDEN BY THE ELEMENTS OF VECTOR)
void makeOddEven(Node* &head){
    Node *temp = head;
    vector<int> arr;
    while(temp != nullptr){    //push odd nodes
        arr.push_back(temp->data);
        temp= temp->next;
        if (temp != nullptr) {
            temp = temp->next;
        }
    }
    temp = head ? head->next : nullptr;
    while(temp  != nullptr){  //push even nodes
        arr.push_back(temp->data);
        temp= temp->next;
        if (temp != nullptr) {
            temp = temp->next;
        }
    }
    temp = head;
    for(int i=0; i< arr.size(); i++){    //override data of LL
        temp->data= arr[i];
        temp= temp->next;
    }
}
//Brute-2 (HERE WE ARE CREATING NEW LIST LINK STARTING FROM ODD LIST ENDED WITH EVEN LIST)
void makeOddEven2(Node* &head){
    Node* fnode = new Node(0);
    Node * curr = fnode;
    Node *temp = head;
    while(temp != nullptr){
        Node *newNode = new Node(temp->data);
        curr->next = newNode;
        temp= temp->next;
        if (temp != nullptr) {
            temp = temp->next;
        }
        curr = curr->next;
    }

    temp = head ? head->next : nullptr;
    while(temp != nullptr){
        Node *newNode = new Node(temp->data);
        curr->next = newNode;
        temp= temp->next;
        if (temp != nullptr) {
            temp = temp->next;
        }
        curr = curr->next;
    } 
    head=fnode->next;   //update head to 2nd node of new LL(bcoz initial node is 0)
}
//Optimal
void makeOddEven3(Node* &head){   //HERE WE ARE CHANGING ACTUAL LL
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;   //save the head location of even list 

    while(even!=NULL && even->next!=NULL){
        odd->next = even->next;     //link odd nodes
        odd = odd->next;
        even->next = odd->next;     //link even nodes
        even = even->next;
    }
    odd->next = evenHead;        //link even node at the end of odd nodes(attach even list to odd list)
}
Node* reversebyK(Node* &head, int k){
    //base case
    if(head == NULL) return NULL;

    //step-1 : Reverse first K node
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    //step-1 : Baki Recursion sambhal lega
    if(next != NULL){
        head->next = reversebyK(next, k);   //after reverse, head becomes the last node. So attach next reversed list to it.
    }
    return prev;    //it returns the head of reversed LL
}
bool isCircular2(Node *head){     // Brute (O(N)  |  O(N))
    map<Node*, bool> mp;
    Node *temp = head;
    while(temp != NULL){
        if(mp[temp] == true) return true;
        mp[temp] = true;
        temp = temp->next;
    }
    return false;
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
bool detectLoop(Node* head){
    if(head == NULL) return false;

    map<Node* , bool> mp;
    Node *temp = head;
    while(temp != NULL){
        if(mp[temp] == true){
            cout<<"Loop detect on node "<<temp->data<<endl;
            return true;
        }
        mp[temp] = true;
        temp = temp->next;
    }
    return false;
}
Node* floydDetectLoop(Node *head){
    if(head == NULL) return NULL;

    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        if(slow == fast){
            // cout<<"Loop detect at node "<<fast->data<<endl;
            return fast;  //slow also works
        }
    }
    return NULL;
}
Node* getStaringNode(Node *head){
    if(head == NULL) return NULL;

    Node *intersection = floydDetectLoop(head);  //where initial fast & slow meet
    Node *slow = head;
    while(slow != intersection){   //inc slow & intersection by 1, after some time they'll be at same node(which called staring node of loop)
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void removeLoop(Node *head){
    if(head == NULL) return;

    Node *loopNode = getStaringNode(head);
    Node *temp = loopNode;
    while(temp->next != loopNode){
        temp = temp->next;
    }
    temp->next = NULL;    //marking last node of loop as NULL
    cout<<"Loop removed ! "<<endl;
}
void removeDuplicates(Node* head){    //It requires sorted LL in i/p
    Node *curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            Node *nodeToDelete = curr->next;
            curr->next = curr->next->next;
            nodeToDelete->next = NULL;     //imp. else code will run infinite bcoz nodeToDelete will point to memory address without data(but we want its NULL as code written in destructor)
            delete nodeToDelete;
        }
        else{
            curr = curr->next;
        }
    }
}
// Brute    O(N2)  |  O(1)
void removeDuplicatesUnsorted(Node *head){
    Node *curr = head;
    while(curr != NULL){
        Node *prev = curr;
        Node *temp = curr->next;
        while(temp != NULL){
            if(temp->data == curr->data){
                Node *nodeToDelete = temp;
                prev->next = temp->next;
                temp = temp->next;  // Move temp to the next node before deleting
                nodeToDelete->next = NULL;
                delete nodeToDelete;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        curr= curr->next;
    }
}
//better    O(N)  |  O(N) 
void removeDuplicatesUnsorted2(Node *head){
    map<int, bool> visited;
    Node *temp = head;
    Node *prev = NULL;
    while(temp != NULL){
        if(visited[temp->data] == true){
            Node *nodeToDelete = temp;
            prev->next = temp->next;
            temp = temp->next;
            nodeToDelete->next = NULL;    //before deleting any node, make its next ptr NULL
            delete nodeToDelete;
        }
        else{
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
}
Node* rotateByK(Node* head, int k) {
    Node *temp = head;
    Node *prev = NULL;
    //Make LL circular;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    //Trav till next-head
    temp = head;
    while(k>0){
        prev = temp;
        temp = temp->next;
        k--;
    }
    prev->next = NULL;  //mark prev as end node of rotated LL
    return temp;    //Now temp is head of Rotated LL
}
void sort012(Node* &head){
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            countZero++;
        }
        else if(temp->data == 1){
            countOne++;
        }
        else if(temp->data == 2){
            countTwo++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(countZero != 0){
            temp->data = 0;
            countZero--;
        }
        else if(countOne != 0){
            temp->data = 1;
            countOne--;
        }
        else if(countTwo != 0){
            temp->data = 2;
            countTwo--;
        }
        temp = temp->next;
    }
}
void insertAtTail(Node* &tail, Node *curr){
    tail->next = curr;
    tail = curr;
}
//When exhange/Override of data is not allowed
void sort012_new(Node* &head){
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    //create seperate list for 0s, 1s & 2s
    while(curr != NULL){
        int val = curr->data;
        if(val == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1){
            insertAtTail(oneTail, curr);
        }
        else{
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    //Merge 3 sublist
    if(oneHead->next != NULL){          //1s list is not empty
        zeroTail->next = oneHead->next;
    }
    else{                               //1s list is empty
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //Head setup
    head = zeroHead->next;           //bcoz all sublist starting from node=-1

    //delete dummy nodes
    zeroHead->next = NULL;           //as code written in destructor
    delete zeroHead;
    oneHead->next = NULL;
    delete oneHead; 
    twoHead->next = NULL;
    delete twoHead;
}
//Merge 2 sorted LL
Node *merge(Node* first, Node *second){
    //If only 1 node is present in first LL
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            //Add node in between the node of first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            //Update the pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //Go one step ahead in first list
            curr1 = next1;             //curr1 = curr1->next;
            next1 = next1->next;       //next1 = next1->next;
            //If first list is empty
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node *merge2Sorted(Node *first, Node* second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data <= second->data){
        return merge(first, second);
    }
    else{
        return merge(second, first);
    }
}
//Check Palindrome or not
bool isPalindrome(Node *head){      //O(N)  |  O(N)
    vector<int> arr;
    Node *temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int s=0, e=arr.size()-1;
    while(s<=e){
        if(arr[s] != arr[e]){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}
bool isPalindrome2(Node *head){      //O(N)  |  O(1)
    Node *temp1 = head;
    Node *mid = getMiddle2(head); 
    Node *temp2 = reverse(mid);
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp2->next;
            temp2 = temp2->next;
        }
    }
    return true;
}
//Add two LL
void insertAtTail(Node* &head, Node* &tail, int val){
    Node *temp = new Node(val);
    //empty list
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}
Node *add(Node* first, Node* second){
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL) 
            val1 = first->data;
        
        int val2 = 0;
        if(second != NULL)
            val2 = second->data;
            
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        
        //Create node and add in ans LL
        insertAtTail(ansHead, ansTail, digit);
        
        carry = sum/10;
        
        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
    }
    return ansHead;
}
Node* addTwoLL(Node* first, Node* second)
{
    //Step-1 : Reverse input LL
    first = reverse(first);
    second = reverse(second);
    
    //Step-2 : Add 2 LL
    Node *ans = add(first, second);
    
    //Step-3 : reverse ans LL
    ans = reverse(ans);
    // return ans;
    //to handle starting zero's node
    while(ans->data == 0 && ans->next != NULL){
        ans = ans->next;
    }
    return ans;
}
int main(){
    //create new node
    Node *fnode = new Node(1);
    cout<<fnode->data<<endl;
    cout<<fnode->next<<endl;

    //head pointed to node1
    Node *head = fnode;
    Node *tail = fnode;
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(tail, head, 3, 20);
    print(head);
    deleteNode(4, head, tail);
    print(head);
    insertAtPosition(tail, head, 4, 16);
    print(head);
    cout<<"Node Count : "<<nodeCount(head)<<endl;
    insertAtTail(tail, 30);
    print(head);
    reverse(head);
    print(head);
    // insertAtTail(tail, 40); //insertAtTail() will not work properly after reverse(). bcoz tail ptr was not updated, only head was updated in reverse(). It'll work after reverseUpdateTail().
    // print(head);
    sort(head);
    print(head);
    Node *mid = getMiddle2(head);
    cout<<"Middle Node = "<<mid->data<<endl;
    Node* rotatedHead = rotateByK(head, 3);
    print(rotatedHead);
    // cout << "head " << head -> data << endl;
    // cout << "tail " << tail -> data << endl;
    // printOddEven(head);
    // // printEven(head);
    // makeOddEven2(head);
    // print(head);
    // head = reversebyK(head, 2);
    // print(head);
    // cout<<(isCircular2(tail) ? "LL is Circular!" : "LL is not Circular!")<<endl;
    
    //creating loop in a LL
    // tail->next = head->next->next;    //16//comment above code as tail ptr is not updated
    // // print(head);            //infinite run
    // cout<<(detectLoop(head) ? "Loop is present" : "Loop is not present")<<endl;
    // cout<<(floydDetectLoop(head) != NULL ? "Loop is present" : "Loop is not present")<<endl;
    // Node *loopNode = getStaringNode(head);
    // cout<<"Loop starts at node : "<<loopNode->data<<endl;
    // removeLoop(head);
    // print(head);

    // insertAtTail(tail,10);
    // insertAtTail(tail,30);
    // print(head);
    // // sort(head);
    // // print(head);
    // // removeDuplicates(head);
    // // print(head);
    // removeDuplicatesUnsorted2(head);
    // print(head);

    // insertAtTail(tail,0);
    // insertAtTail(tail,2);
    // insertAtTail(tail,2);
    // insertAtTail(tail,0);
    // insertAtTail(tail,1);
    // insertAtTail(tail,0);
    // insertAtTail(tail,2);
    // insertAtTail(tail,2);
    // print(head);
    // // sort012(head);
    // sort012_new(head);
    // print(head);

//Merge 2 sorted LL
    // Node *node1 = new Node(1);
    // Node *first = node1;
    // Node *node2 = new Node(2);
    // Node *second = node2;

    // insertAtTail(node1, 3);
    // insertAtTail(node1, 5);

    // insertAtTail(node2, 4);
    // insertAtTail(node2, 5);
    // print(first);
    // print(second);
    // Node *mergedLL = merge2Sorted(first, second);
    // print(mergedLL);

//Check Palindrome or not
    // insertAtTail(tail, 2);
    // insertAtTail(tail, 1);
    // print(head);
    // cout<<(isPalindrome2(head) ? "Palindrome" : "Not Palindrome")<<endl;

//Add two LL
    // Node *node1 = new Node(1);  
    // Node *first = node1;
    // Node *tail1 = node1;
    // insertAtTail(tail1, 4);
    // insertAtTail(tail1, 5);
    // print(first);   //145

    // Node *node2 = new Node(4);  
    // Node *second = node2;
    // Node *tail2 = node2;
    // insertAtTail(tail2, 5);
    // print(second);  //45
    // Node *add = addTwoLL(first, second);
    // print(add);     //145 + 45 = 190
}