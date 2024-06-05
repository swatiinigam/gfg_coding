//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int solve(int n, int m, vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        if (i >= n || j >= m) {
            return 0;
        }
      
        if (mat[i][j] == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int right = solve(n, m, mat, i, j + 1, dp);
        int down = solve(n, m, mat, i + 1, j, dp);
        int diagonal = solve(n, m, mat, i + 1, j + 1, dp);
        
        dp[i][j] = 1 + min({right, down, diagonal});
        return dp[i][j];
    }
public:
    int maxSquare(int n, int m, vector<vector<int>>& mat) {
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    maxi = max(maxi, solve(n, m, mat, i, j, dp));
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends