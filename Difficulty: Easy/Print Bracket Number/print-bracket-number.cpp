//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    std::vector<int> bracketNumbers(std::string str) {
        int openCount = 0;
      // int closeCount = 1;
        int n = str.size();
        std::vector<int> result;
        stack<int>s;
        
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                   openCount++;
                result.push_back(openCount);
             
                s.push(openCount);
            } else if (str[i] == ')') {
                result.push_back(s.top());
                s.pop();
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends