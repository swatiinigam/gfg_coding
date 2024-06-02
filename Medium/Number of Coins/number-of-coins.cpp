//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo; // Memoization table
    
    int solve(vector<int>& coins, int M, int V, int sum) {
        if (sum == V) {
            return 0;
        }
        if (sum > V) {
            return -1; // Invalid path
        }
        
        // Check if the result for the current sum is already calculated
        if (memo.count(sum)) {
            return memo[sum];
        }
        
        int minCoins = INT_MAX;
        
        // Try all possible coins and choose the one that gives the minimum number of coins
        for (int i = 0; i < M; ++i) {
            int result = solve(coins, M, V, sum + coins[i]);
            if (result != -1) {
                minCoins = min(minCoins, result + 1);
            }
        }
        
        // Update the memoization table
        memo[sum] = (minCoins == INT_MAX) ? -1 : minCoins;
        
        return memo[sum];
    }
    
public:
    int minCoins(vector<int>& coins, int M, int V) {
        return solve(coins, M, V, 0);
    }
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends