//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <vector>
#define MOD 1000000007

class Solution {
private:
    int Fibonacci(int n, std::vector<int>& dp) {
        // Base cases
        if (n == 0 || n == 1) {
            return n;
        }
        // Return the cached value if already computed
        if (dp[n] != -1) {
            return dp[n];
        }
        // Compute the value and store it in the dp array
        dp[n] = (Fibonacci(n - 2, dp) + Fibonacci(n - 1, dp)) % MOD;
        return dp[n];
    }

public:
    int nthFibonacci(int n) {
        // Initialize the dp array with -1 to indicate uncomputed values
        std::vector<int> dp(n + 1, -1);
        // Start the computation
        return Fibonacci(n, dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends