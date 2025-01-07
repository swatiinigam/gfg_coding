//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        int str1SubsequenceCount = countDistinctSubsequences(str1);
        int str2SubsequenceCount = countDistinctSubsequences(str2);
        return str1SubsequenceCount >= str2SubsequenceCount ? str1 : str2;
    }
    int countDistinctSubsequences(string str)
    {
        int n = str.size();
        // dp array to store counts
        vector<int> dp(n + 1, 0);
        // Empty string has one subsequence
        dp[0] = 1;
        // To store the last occurrence index of each character
        vector<int> last(26, -1);
        for (int i = 1; i <= n; i++)
        {
            // Double the count from the previous position
            dp[i] = 2 * dp[i - 1];
            // If the current character has occurred before
            if (last[str[i - 1] - 97] != -1)
            {
                // Subtract the count of subsequences ending at the last occurrence
                dp[i] = dp[i] - dp[last[str[i - 1] - 97]];
            }
            // Update the last occurrence index of the current character
            last[str[i - 1] - 97] = i - 1;
        }
        // Return the total count of distinct subsequences
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends