//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
# define MOD 1000000007

class Solution{
public:
    int solve(int n,int r,vector<vector<int>> &dp){
        if(r==0 or r == n) return 1;
        if(dp[n][r]!=-1) return dp[n][r];
        dp[n][r] = (solve(n-1,r-1,dp)+solve(n-1,r,dp))%MOD;
        return dp[n][r];
    }
    int nCr(int n, int r){
        // code here
       if(r>n) return 0;
       
       vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
       return solve(n,r,dp);
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends