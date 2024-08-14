//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    int solve(string &str1, string &str2, int i, int j, int &maxLength, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Check if the current characters of str1 and str2 match
        if (str1[i - 1] == str2[j - 1]) {
            dp[i][j] = solve(str1, str2, i - 1, j - 1, maxLength, dp) + 1;
            maxLength = max(maxLength, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }
        
        // Return the value stored in dp[i][j]
        return dp[i][j];
    }

public:
    int longestCommonSubstr(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int maxLength = 0;
        
        // Initialize a DP table with -1 for memoization
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        // Calculate the longest common substring length
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                solve(str1, str2, i, j, maxLength, dp);
            }
        }
        
        return maxLength;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends