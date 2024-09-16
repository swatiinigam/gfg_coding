//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int total_cost(vector<vector<int>>cost) {
        int n = cost.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1)); // dp[mask][i]: minimum cost to visit all nodes in mask ending at node i

        return tspUtil(cost, 1, 0, dp); // Start from node 0 with mask 1 (indicating node 0 is visited)
    }

private:
    int tspUtil(vector<vector<int>>& cost, int mask, int u, vector<vector<int>>& dp) {
        int n = cost.size();
        if (mask == (1 << n) - 1) {
            return cost[u][0]; // Return to the starting city
        }
        if (dp[mask][u] != -1) {
            return dp[mask][u];
        }

        int ans = INT_MAX; // Use INT_MAX to find the minimum
        for (int v = 0; v < n; ++v) {
            if (!(mask & (1 << v))) { // If city v is not visited
                int newCost = cost[u][v] + tspUtil(cost, mask | (1 << v), v, dp);
                ans = min(ans, newCost);
            }
        }

        return dp[mask][u] = ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends