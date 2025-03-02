#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *buildTree(node *root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversalSingleLine(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);       //(SEPERATOR)to add ENTER after each level

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level has been completed
            cout<<endl;
            if(!q.empty()){
                //q still have some child nodes
                q.push(NULL);       //to add ENTER after each level
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void reverseLevelOrderTraversal(node* root) {
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);  // (SEPARATOR) to mark the end of a level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            s.push(NULL);  // Push NULL to mark the end of a level in the stack
            if (!q.empty()) {
                q.push(NULL);  // Push NULL to mark the end of the next level in the queue
            }
        } 
        else {
            s.push(temp);  // Push the node to the stack
            if (temp->right) {  // Push the right child first to maintain reverse order
                q.push(temp->right);
            }
            if (temp->left) {  // Then push the left child
                q.push(temp->left);
            }
        }
    }
    // Print the nodes in reverse level order
    while (!s.empty()) {
        node *temp = s.top();
        s.pop();

        if (temp == NULL) {
            cout << endl;  // Print a new line when a level ends
        } else {
            cout << temp->data << " ";
        }
    }
}
void reverseLevelOrderTraversal2(node *root) {
    if (!root) return;
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Separator for levels
    
    vector<vector<int>> v;
    vector<int> currentLevel;

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            v.push_back(currentLevel);
            currentLevel.clear();

            if (!q.empty()) {
                q.push(NULL);  // Add separator for the next level
            }
        } else {
            currentLevel.push_back(temp->data);

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

    // Print levels in reverse order
    for (int i = v.size() - 1; i >= 0; i--) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void inOrder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root = new node(data);

    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        
        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
//No. of leaf node present in the tree
void inorder(node* root, int &count){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left, count);

    //leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    inorder(root->right, count);
}
int noOfLeafNodes(node *root){
    int cnt=0;
    inorder(root, cnt);
    return cnt;
}
//Q1.Depth / Height of binary tree
int height(node *root){     //O(N) | O(N)
    //Base case
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
//Q2.Diameter of BT(Longest path between two end nodes)
//Brute   O(N2) | O(height)
int diameter(node *root){
    //Base case
    if(root == NULL) return 0;

    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) +1+ height(root->right);

    int ans = max(opt1, max(opt2, opt3));
    return ans;
}
//Optimal   O(N) | O(height)
pair<int, int> diameterFast(node *root){    //first indicates diameter, second indicates height of BT
    //Base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;   //return {0,0};
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    
    int opt1 = left.first;      
    int opt2 = right.first;
    int opt3 = left.second +1+ right.second;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) +1;
    return ans;
}
int diameterOptimal(node *root){
    return diameterFast(root).first;
}
//Q3.Check for Balance Tree (if [height(left) subtree - height(rigth) subtree] <=1 then BT is Balance)
//Brute    O(N2) | O(height)
bool isBalanced(node *root){
    //base case
    if(root == NULL) return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
} 
//Optimal   O(N) | O(height)
pair<bool,int> isBalancedFast(node *root){
    //Base case
    if(root == NULL){
        return {true, 0};
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second, right.second) +1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}
bool isBalancedOptimal(node *root){
    return isBalancedFast(root).first;
}
//Q4.Check two trees are identical or not
bool isIdentical(node *r1, node *r2){       //O(N)
    //Base cases
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
//Q5.Check sum of both part of tree is same or not (for all nodes)
pair<bool,int> isSumTreeFast(node *root){    //O(N) | O(height)
    //Base case
    if(root == NULL){
        return {true, 0};
    }
    //Leaf node
    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == (leftSum + rightSum);

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && condn){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;   //2*root->data also work
    }
    else{
        ans.first = false;
    }
    return ans;
}
bool isSumTree(node *root){
    return isSumTreeFast(root).first;
}
int main(){
    //Creating a tree
    node *root = NULL;
    root = buildTree(root);
    //Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1    PASTE(ctrl+shift+v)
    //level order traversal
    cout<<"Level order Traversal : "<<endl;
    levelOrderTraversal(root);
    // cout<<"Reverse Level order Traversal : "<<endl;
    // reverseLevelOrderTraversal(root);

    // cout << "inorder traversal is:  ";
    // inOrder(root); 

    // cout << endl << "preorder traversal is:  ";
    // preOrder(root); 

    // cout << endl << "postorder traversal is:  ";
    // postOrder(root);
    
    // node *root = NULL;
    // buildFromLevelOrder(root);   //no need to store in root
    // levelOrderTraversal(root);   //Input : 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
     
    // cout<<"No of leaf nodes = "<<noOfLeafNodes(root)<<endl;
    cout<<"Height of tree = "<<height(root)<<endl;
    // cout<<"Longest path = "<<diameter(root)<<endl;
    // cout<<"Longest path = "<<diameterOptimal(root)<<endl;
    cout<<(isBalanced(root) ? "Balanced!" : "Not balanced!")<<endl;
    // cout<<(isBalancedOptimal(root) ? "Balanced!" : "Not balanced!")<<endl;

    // node *root2 = NULL;
    // root2 = buildTree(root2);
    // cout<<(isIdentical(root, root2) ? "Identical" : "Not identical")<<endl;

    cout<<endl<<(isSumTree(root) ? "Sum Tree" : "Not sum tree");
return 0;
}