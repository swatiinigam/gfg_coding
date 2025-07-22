class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int d = 1;
        set<int>s(arr.begin(),arr.end());
        for(auto x : s){
            if(x>=1){
                if(x != d) return d;
                d++;
            }
        }
        int last = *s.rbegin();
        if(last<1) return 1;
        return last+1;
    }
};