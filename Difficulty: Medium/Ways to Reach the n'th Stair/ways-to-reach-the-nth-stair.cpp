//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count number of ways to reach the nth stair.
    int rec(int n){
        if(n==0 || n==1) return 1;
        
        return rec(n-1)+rec(n-2);
    }
    int memo(int n,vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(dp[n] != -1) return dp[n];
        
        dp[n] = memo(n-1,dp) + memo(n-2,dp);
        return dp[n];
    }
    int tabu(int n){
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int tabuSpaceOptimized(int n){
        int prev = 1;
        int curr = 1;
        
        for(int i=2;i<=n;i++){
            int ans = prev+curr;
            prev = curr;
            curr = ans;
        }
        return curr;
    }
    int countWays(int n) {
        // your code here

        int ans = tabuSpaceOptimized(n);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends