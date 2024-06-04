//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int solve(int n, std::vector<int>& dp) {
        if (n == 0) {
            return 0;
        }

        // If the result for n is already calculated, return it.
        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = n;
        for (int i = 1; i * i <= n; i++) {
            int temp = i * i;
            ans = std::min(ans, 1 + solve(n - temp, dp));
        }

        // Memoize the result for n.
        dp[n] = ans;
        return dp[n];
    }

public:
    int MinSquares(int n) {
        // Code here
        std::vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends