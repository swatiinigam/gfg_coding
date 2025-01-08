//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    Node *left(Node *root){ // left rotaion
        if(!root->right) return root;
        Node *tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        return tmp;
    }

    Node *right(Node *root){ // right rotaion
        if(!root->left) return root;
        Node *tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        return tmp;
    }
    
    Node *RL(Node *root){ // right left rotaion
        root->right = right(root->right);
        return left(root);
    }
    
    Node *LR(Node *root){ // left right rotaion
        root->left = left(root->left);
        return right(root);
    }
    
    int height(Node *root){ // updating heights of tree nodes
        if(!root) return 0;
        root->height = 1+max(height(root->left),height(root->right));
        return root->height;
    }

    Node* insertToAVL(Node* root, int data)
    {
        int a=(root and root->left)? root->left->height:0;
        int b=(root and root->right)? root->right->height:0;
        if(!root){
            Node *ptr = new Node(data);
            ptr->left = NULL;
            ptr->right = NULL;
            ptr->height = 1;
            return ptr;
        }
        else if(data < root->data){
            root->left = insertToAVL(root->left,data);
            a = root->left->height;
        }
        else{
            root->right = insertToAVL(root->right,data);
            b = root->right->height;
        }
        
        if(a-b > 1 or a-b < -1){ // checking balance factor
            int c=0,d=0;
            if(a>b){ // problem in Left subTree
                if(a and root->left->left) c = root->left->left->height;
                if(root->left and root->left->right) d = root->left->right->height;
                if(c < d) root = LR(root); // left right rotation
                else root = right(root); // right rotation
            }
            else{ // problem in Right subTree
                if(b and root->right->left) c = root->right->left->height;
                if(b and root->right->right) d = root->right->right->height;
                if(c>d) root = RL(root); // right left rotaion
                else root = left(root); // left rotaion
            }
            a = height(root->left);
            b = height(root->right);
        }
        root->height = max(a,b)+1;
        return root;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends