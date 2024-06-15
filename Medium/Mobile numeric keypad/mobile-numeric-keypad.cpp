//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, long long>> memo;
    vector<int> adj[10];

    Solution() {
        adj[0] = {0, 8};
        adj[1] = {1, 2, 4};
        adj[2] = {2, 1, 3, 5};
        adj[3] = {3, 2, 6};
        adj[4] = {4, 1, 5, 7};
        adj[5] = {5, 2, 4, 6, 8};
        adj[6] = {6, 3, 5, 9};
        adj[7] = {7, 4, 8};
        adj[8] = {8, 0, 5, 7, 9};
        adj[9] = {9, 6, 8};
    }

    long long countWays(int length, int digit) {
        // Base case: if the length is 1, return 1
        if (length == 1) return 1;

        // Check if the result is already in the memo
        if (memo[length].count(digit)) return memo[length][digit];

        // Recursive case: calculate the count for the current digit and length
        long long totalWays = 0;
        for (int nextDigit : adj[digit]) {
            totalWays += countWays(length - 1, nextDigit);
        }

        // Store the result in the memo and return it
        memo[length][digit] = totalWays;
        return totalWays;
    }

    long long getCount(int n) {
        long long ans = 0;
        for (int digit = 0; digit <= 9; digit++) {
            ans += countWays(n, digit);
        }
        return ans;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends