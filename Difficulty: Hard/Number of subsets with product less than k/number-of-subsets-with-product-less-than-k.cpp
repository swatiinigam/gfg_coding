//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    // Recursive function with memoization to calculate the number of subsets
    int solve(int i, int product, int arr[], int N, int K, vector<vector<int>>& dp) {
        // Base case: If we've considered all elements
        if (i == N) {
            return 0;
        }
        // If the product already exceeds K, return 0
        if (product > K) {
            return 0;
        }
        // Memoization check
        if (dp[i][product] != -1) {
            return dp[i][product];
        }
        
        // Option 1: Include the current element in the subset
        int include = 0;
        if (product * arr[i] <= K) {
            include = 1 + solve(i + 1, product * arr[i], arr, N, K, dp);
        }

        // Option 2: Exclude the current element from the subset
        int exclude = solve(i + 1, product, arr, N, K, dp);
        
        // Store the result in dp array and return the sum of both options
        dp[i][product] = include + exclude;
        return dp[i][product];
    }

public:
    int numOfSubsets(int arr[], int N, int K) {
        // Initialize a dp array for memoization
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
        // Start from index 0 and product 1 (since the product starts as 1)
        return solve(0, 1, arr, N, K, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends