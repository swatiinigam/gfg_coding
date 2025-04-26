//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int count(Node *root){
        if(!root) return 0;
        
        return 1 + count(root->left) + count(root->right);
    }
    
    bool isCompleteBinaryTree(Node* root,int index, int total_nodes){
        if(!root) return true;
        
        if(index >= total_nodes) return false;
        
        return isCompleteBinaryTree(root->left,2*index+1, total_nodes) && isCompleteBinaryTree(root->right, 2*index + 2, total_nodes);
    }
    
    bool checkMaxHeap(Node* root){
        if(root->left){
            if(root->data < root->left->data) return false;
            if(!checkMaxHeap(root->left)) return false;
        }
        
        if(root->right){
            if(root->data < root->right->data) return false;
            if(!checkMaxHeap(root->right)) return false;
        }
        
        return true;
    }
    
    bool isHeap(Node* tree) {
        // code here
        int total_nodes = count(tree);
        
        if(!isCompleteBinaryTree(tree, 0 , total_nodes)) return false;
        
        if(!checkMaxHeap(tree)) return false;
        
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends