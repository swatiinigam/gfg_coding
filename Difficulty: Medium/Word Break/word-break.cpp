//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
       int wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  

        for (int i = 0; i < n; i++) {
            if (!dp[i])
                continue;
            for (const string &word : dictionary) {
                int len = word.size();
           
                if (i + len <= n && s.substr(i, len) == word) {
                    dp[i + len] = true;
                }
            }
        }
        return dp[n] ? 1 : 0;
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends