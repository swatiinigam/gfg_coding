//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    int solve(int A[], int n, int i, int diff, vector<vector<int>>& memo) {
        if (i == n) {
            return 0;
        }
        
        if (memo[i][diff] != -1) {
            return memo[i][diff];
        }
        
        int ans = 0;
        int next = A[i] + diff;
        int idx = lower_bound(A, A + n, next) - A;

        if (idx < n && A[idx] == next) {
            ans = 1 + solve(A, n, idx, diff, memo);
        }
        
        return memo[i][diff] = ans;
    }

public:
    int lengthOfLongestAP(int A[], int n) {
        if (n <= 2) {
            return n;
        }

        vector<vector<int>> memo(n, vector<int>(A[n - 1] - A[0] + 1, -1));
        int ans = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                int cnt = 1;
                
                if (memo[j][diff] != -1) {
                    cnt = memo[j][diff];
                }
                
                memo[i][diff] = cnt + 1;
                ans = max(ans, memo[i][diff]);
            }
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
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends