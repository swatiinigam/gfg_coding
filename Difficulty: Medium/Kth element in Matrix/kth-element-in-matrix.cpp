class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        int ans = -1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            
            for(vector <int>& arr: matrix){
                cnt += upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            }
            
            if(cnt >= k){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};