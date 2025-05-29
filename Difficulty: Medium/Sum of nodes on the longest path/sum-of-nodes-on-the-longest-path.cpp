/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        queue<pair<Node *,int>>q;
        q.push({root,root->data});
        int res=0;
        while(!q.empty()){
            int n=q.size();
            int curr_max=0;
            for(int i=0;i<n;++i){
            auto p=q.front();
            q.pop();
            auto node=p.first;
            int curr_sum=p.second;
            if(node->left){
                 q.push({node->left,node->left->data+curr_sum});
            }
            if(node->right){
                q.push({node->right,node->right->data+curr_sum});
            }
            curr_max=max(curr_sum,curr_max);
            }
            if(q.size()==0)res=curr_max;
        }
        return res;
        
    }
};