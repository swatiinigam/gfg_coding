class Solution {
    vector<int> ans;
    void fun(vector<int> &preorder){
        vector<int> left,right;
        int n = preorder.size();
        for(int i=1;i<n;i++){
            if(preorder[i] < preorder[0]) left.push_back(preorder[i]);
            else right.push_back(preorder[i]);
        }
        if(left.size() == 0 and right.size() == 0){
            ans.push_back(preorder[0]);
            return;
        }
        if(left.size()) fun(left);
        if(right.size()) fun(right);
    }
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        int n = preorder.size();
        fun(preorder);
        return ans;
    }
};