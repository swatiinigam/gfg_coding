//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
private:
    int solve(int W, int wt[], int val[], int n, int i, vector<vector<int>> &memo) {
        // Base cases
        if (i >= n || W == 0) {
            return 0;
        }
        
        // Check if the result for this subproblem is already computed
        if (memo[i][W] != -1) {
            return memo[i][W];
        }
        
        int maxprofit;
        
        // If weight of the current item is more than the remaining capacity, skip this item
        if (wt[i] > W) {
            maxprofit = solve(W, wt, val, n, i + 1, memo);
        } else {
            // Either include the current item or exclude it
            maxprofit = max(val[i] + solve(W - wt[i], wt, val, n, i + 1, memo), solve(W, wt, val, n, i + 1, memo));
        }
        
        // Store the result in the memoization table and return
        memo[i][W] = maxprofit;
        return maxprofit;
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        // Initialize a memoization table with -1
        vector<vector<int>> memo(n, vector<int>(W + 1, -1));
        return solve(W, wt, val, n, 0, memo);
    }
};



//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends