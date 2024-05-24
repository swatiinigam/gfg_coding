//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &arr, int i, int d, vector<vector<int>>&dp, int bais, int left){
        if(i == arr.size()){
            return d == 0? 1: 0;
        }
        if(left < d)
            return 0;
        if(dp[i][d+ bais] != -1)
            return dp[i][d+bais];
        dp[i][d+ bais] = ((long long)solve(arr, i+1, d+ arr[i], dp, bais, left - arr[i]) +
                        solve(arr, i+1, d- arr[i], dp, bais, left - arr[i]))%1000000007;
        return dp[i][d+bais];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0;
        
        for(auto a : arr)
            sum += a;
        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));
        return solve(arr, 0, d, dp, sum-d, sum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends