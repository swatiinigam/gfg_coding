class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        sort(arr.begin(),arr.end(),[x](const int &a,const int &b){
            if(abs(a-x) == abs(b-x)){
                return a>b;
            }
            return abs(a-x) < abs(b-x);
        });
        vector<int> ans;
        for(auto it : arr){
            if(it!=x){
                ans.push_back(it);
                if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};