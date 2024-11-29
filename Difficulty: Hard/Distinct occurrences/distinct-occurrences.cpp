//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

const int mod = 1e9 + 7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i <= n; ++i) dp[i][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = (s[i - 1] == t[j - 1]) ? ((dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod)
                                                  : dp[i - 1][j] % mod;
            }
        }
        return dp[n][m] % mod;
    }
};


//{ Driver Code Starts.

//  Driver code to check above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends