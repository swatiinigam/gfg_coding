//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
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
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
private:
    int solve(Node* root, int k, int currentSum, unordered_map<int, int>& prefixSumCount) {
        if (!root) {
            return 0;
        }
        
        // Update the current prefix sum
        currentSum += root->data;
        
        // Number of paths with sum equal to k
        int cnt = 0;
        
        // Check if there's a prefix sum that we can subtract to get sum k
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            cnt += prefixSumCount[currentSum - k];
        }
        
        // Update the map with the current prefix sum
        prefixSumCount[currentSum]++;
        
        // Recur for left and right subtrees
        cnt += solve(root->left, k, currentSum, prefixSumCount);
        cnt += solve(root->right, k, currentSum, prefixSumCount);
        
        // Remove the current prefix sum from the map before returning to the parent node (backtracking)
        prefixSumCount[currentSum]--;
        
        return cnt;
    }

public:
    int sumK(Node *root, int k) {
        unordered_map<int, int> prefixSumCount;
        // Base case to handle the sum from the root to the current node
        prefixSumCount[0] = 1;
        return solve(root, k, 0, prefixSumCount);
    }
};



//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends