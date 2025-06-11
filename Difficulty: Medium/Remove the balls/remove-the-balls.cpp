class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<int>st;
        st.push(0);
        
        for(int i=1;i<color.size();i++){
            int el=-1;
            if(!st.empty()) el=st.top();
            
            if(el!=-1&&color[i]==color[el]&&radius[i]==radius[el]){
                st.pop();
            }else{
                st.push(i);
            }
            
        }
        return st.size();
    }
};