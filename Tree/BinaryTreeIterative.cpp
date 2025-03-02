#include <iostream>
#include <queue>
#include <stack> // Include stack header for iterative methods
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root) {
    cout << "Enter the data : ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversalSingleLine(node *root) {
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL); // to add ENTER after each level

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            // previous level has been completed
            cout << endl;
            if (!q.empty()) {
                // q still has some child nodes
                q.push(NULL); // to add \n(ENTER) after each level
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node *root) {
    stack<node*> s;
    node *curr = root;

    while (curr != NULL || !s.empty()) {
        // Reach the left most Node of the curr Node
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        curr = curr->right;
    }
}

void preOrder(node *root) {
    if (root == NULL)
        return;

    stack<node*> s;
    s.push(root);

    while (!s.empty()) {
        node *curr = s.top();
        s.pop();
        cout << curr->data << " ";

        // Push right and then left child to stack
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}

void postOrder(node *root) {
    if (root == NULL)
        return;

    stack<node*> s1, s2;
    s1.push(root);

    // While first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        // Push left and right children of removed item to s1
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    // Print all elements of second stack
    while (!s2.empty()) {
        node *temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    cout << "Enter data for root : ";
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int noOfLeafNodes(node *root) {
    if (root == NULL)
        return 0;

    stack<node*> s;
    s.push(root);
    int count = 0;

    while (!s.empty()) {
        node *curr = s.top();
        s.pop();

        // Check if current node is a leaf node
        if (curr->left == NULL && curr->right == NULL)
            count++;
        else {
            if (curr->right)
                s.push(curr->right);
            if (curr->left)
                s.push(curr->left);
        }
    }
    return count;
}

int main() {
    /*//Creating a tree
    node *root = NULL;
    root = buildTree(root);
    //Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1    PASTE(ctrl+shift+v)
    //level order traversal
    cout<<"Level order Traversal : "<<endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inOrder(root); 

    cout << endl << "preorder traversal is:  ";
    preOrder(root); 

    cout << endl << "postorder traversal is:  ";
    postOrder(root);
    */

    node *root = NULL;

    buildFromLevelOrder(root);   // no need to store in root
    levelOrderTraversal(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout << "No of leaf nodes = " << noOfLeafNodes(root) << endl;

    return 0;
}
