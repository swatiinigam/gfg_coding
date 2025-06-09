/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool isDeadEnd(Node *root, int low = 1, int high = 1e6) {
        if (root == NULL) return false;
        if (root -> left == NULL && root -> right == NULL) return (low >= high);
        int curr = root -> data;
        return (isDeadEnd(root -> left, low, curr - 1) || isDeadEnd(root -> right, curr + 1, high)); 
    }
};