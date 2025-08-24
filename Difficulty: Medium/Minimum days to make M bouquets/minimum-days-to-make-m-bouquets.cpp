class Solution {
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        sort(arr.begin(), arr.end());
        if ( arr.size() <  m * k) return -1;
        return arr[m * k-1];
    }
};