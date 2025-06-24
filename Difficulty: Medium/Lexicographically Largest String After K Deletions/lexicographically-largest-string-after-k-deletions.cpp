class Solution {
  public:
    string maxSubseq(string& s, int k) {
        stack<char>st;
        int n = s.size();
        int i;
        for(i=0;i<n;i++){
            if(k <= 0)break;
            while(!st.empty() and (st.top() < s[i]) and k > 0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        string str = "";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        for(int ku=i;ku<n;ku++){
            str.push_back(s[ku]);
        }
        while(k > 0){
            str.pop_back();
            k--;
        }
        return str;
    }
};
