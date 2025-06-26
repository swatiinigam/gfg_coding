class Solution {
  public:
    int minValue(string &s, int k) {
      
        priority_queue<int>pq;
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        for(auto it:freq){
            pq.push(it);
        }
        for(int i=1;i<=k;i++){
            int tp=pq.top();
            pq.pop();
            pq.push(tp-1);
        }
        int ans=0;
        while(!pq.empty()){
            int val=pq.top();
            pq.pop();
            ans+=val*val;
        }
        return ans;
    }
};