//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void allLCS(vector<vector<int>> &dp, set<string>&st, unordered_map<string, bool> &mp, string &s, string &t, int i, int j, string ds){
        if(i == 0 || j == 0){
            reverse(ds.begin(), ds.end());
            st.insert(ds);
            return;
        }
        string key = to_string(i) + '$' + to_string(j) + '$' + ds;
        if(mp.find(key) != mp.end()) return;
        mp[key] = true;
        if(s[i - 1] == t[j - 1]){
            // if s[i - 1] == t[j - 1] then our dp[i][j] = 1 + dp[i - 1][j - 1] that is we have to include this letter for longest subsequence
            ds.push_back(s[i - 1]);
            allLCS(dp, st, mp, s, t, i - 1, j - 1, ds);
        }
        else{
            if(dp[i][j] == dp[i - 1][j]){
                allLCS(dp, st, mp, s, t, i - 1, j, ds);
            }
            if(dp[i][j] == dp[i][j - 1]){
                allLCS(dp, st, mp, s, t, i, j - 1, ds);
            }
        }
    }
    
    
    
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ds = "";
        // st to store ds made by backtracking
        set<string> st;
        // mp to know that state {i, j, ds} was previously 
        unordered_map<string, bool> mp;
        // Backtracking code for generating all possible LCS
        allLCS(dp, st, mp, s, t, n, m, ds);
        
        // Our final ans
        vector<string> ans (st.begin(), st.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends