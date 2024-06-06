//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
/*private:
    int solve(int n, int a[], int i, int prev_index, vector<vector<int>>& memo) {
        // Base case: if we have considered all elements
        if (i == n) {
            return 0;
        }

        // Check if the result is already computed
        if (memo[i][prev_index + 1] != -1) {
            return memo[i][prev_index + 1];
        }

        // Option 1: Do not include the current element
        int exclude = solve(n, a, i + 1, prev_index, memo);

        // Option 2: Include the current element if it is greater than the previous element
        int include = 0;
        if (prev_index == -1 || a[i] > a[prev_index]) {
            include = 1 + solve(n, a, i + 1, i, memo);
        }

        // Store the result in memo table and return the maximum of the two options
        memo[i][prev_index + 1] = max(include, exclude);
        return memo[i][prev_index + 1];
    }

public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        // Memoization table, initialized with -1
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        // Start the recursion from index 0 with no previous element considered
        return solve(n, a, 0, -1, memo);
    }*/
    
    public:
    int longestSubsequence(int n, int a[])
    {
        vector<int>dp;
        dp.push_back(a[0]);
        
        for(int i=1;i<n;i++)
        {
            if(a[i]>dp.back())
            {
                dp.push_back(a[i]);
            }
            else{
                int ind=lower_bound(dp.begin(), dp.end(), a[i])-dp.begin();
                
                dp[ind]=a[i];
            }
        }
        
        return dp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends