class Solution {
  public:
    int minimumCoins(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), maxi = 0, sum = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }
        vector<int> freq(maxi + 1, 0), suffix(maxi + 1, 0);
        for(int i = 0; i < n; i++) freq[arr[i]]++;
        for(int i = maxi, s = 0; i >= 0; i--) {
            s += freq[i];
            suffix[i] = s;
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] - k > 0) sum += (arr[i] - k);
        }
        ans = sum;
        // cout << sum << " " << ans << endl;
        for(int i = 1; i + k <= maxi; i++) {
            sum += ((i - 1) * freq[i - 1]);
            sum -= suffix[i + k];
            ans = min(ans, sum);
            // cout << sum << " " << ans << endl;
        }
        return ans;
    }
};
