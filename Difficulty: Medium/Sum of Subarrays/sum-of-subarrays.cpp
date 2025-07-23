class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            ans += (i+1)*(n-i)*arr[i];
        }
        return ans;
    }
};