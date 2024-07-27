//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int countMin(string str) {
        int n = str.length();
        string rev_str = string(str.rbegin(), str.rend());
        
        // Memoization table
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        // Calculate LCS length using memoization
        int lcs_length = lcs(str, rev_str, n - 1, n - 1, memo);
        
        // Minimum insertions needed = length of the string - length of the LCS
        return n - lcs_length;
    }

private:
    int lcs(const string& str, const string& rev_str, int i, int j, vector<vector<int>>& memo) {
        // Base cases
        if (i < 0 || j < 0) return 0;
        
        // If already calculated, return from memo
        if (memo[i][j] != -1) return memo[i][j];
        
        // If characters match, move to the next pair of characters
        if (str[i] == rev_str[j]) {
            memo[i][j] = 1 + lcs(str, rev_str, i - 1, j - 1, memo);
        } else {
            // If characters don't match, take the maximum of either excluding the current character of str or rev_str
            memo[i][j] = max(lcs(str, rev_str, i - 1, j, memo), lcs(str, rev_str, i, j - 1, memo));
        }
        
        return memo[i][j];
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends