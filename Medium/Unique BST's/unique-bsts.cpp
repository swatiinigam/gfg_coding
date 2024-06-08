//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define mod 1000000007

class Solution
{   
private:
    int solve(int N, vector<int>& dp)
    {
        if (N == 1 || N == 0) {
            return 1;
        }
        if (dp[N] != -1) {
            return dp[N];
        }
        long long ans = 0; // Use long long to prevent overflow before taking modulus
        for (int i = 1; i <= N; i++) {
            ans = (ans + (long long)solve(i - 1, dp) * solve(N - i, dp)) % mod;
        }
        dp[N] = (int)ans; // Store the result in dp after taking modulus
        return dp[N];
    }
    
public:
    // Function to return the total number of possible unique BSTs. 
    int numTrees(int N) 
    {
        vector<int> dp(N + 1, -1);
        return solve(N, dp);
    }
};



//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends