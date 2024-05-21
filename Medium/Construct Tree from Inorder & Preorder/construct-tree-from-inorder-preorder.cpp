//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    int findPosition(int in[], int element, int inIdxStart, int inIdxEnd){
        for(int i=inIdxStart; i<=inIdxEnd; i++){
            if(in[i] == element) return i;
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &preIdx, int inIdxStart, int inIdxEnd, int n){
        // base case
        if(preIdx >= n || inIdxStart > inIdxEnd) return NULL;
        
        int element = pre[preIdx++];
        Node* root = new Node(element);
        int position = findPosition(in, element, inIdxStart, inIdxEnd);
        
        // recursive calls
        root->left = solve(in, pre, preIdx, inIdxStart, position-1, n);
        root->right = solve(in, pre, preIdx, position+1, inIdxEnd, n);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n){
        int preIdx = 0;
        Node* ans = solve(in, pre, preIdx, 0, n-1, n);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends