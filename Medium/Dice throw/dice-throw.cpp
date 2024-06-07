//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    long long solve(int M, int N, int X, int i, int sum) {
        // Base case: if we have used all dice and the sum matches X
        if (i == N) {
            return sum == X ? 1 : 0;
        }

        long long cnt = 0;
        // Try each face value (from 1 to M) for the current die
        for (int k = 1; k <= M; k++) {
            // Only continue if the current sum is less than or equal to the target sum
            if (sum + k <= X) {
                cnt += solve(M, N, X, i + 1, sum + k);
            }
        }
        return cnt;
    }
    long long solveMemo(int M, int N, int X, int i, int sum,vector<vector<long long>>&dp) {
        // Base case: if we have used all dice and the sum matches X
        if (i == N) {
            return sum == X ? 1 : 0;
        }

        long long cnt = 0;
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        // Try each face value (from 1 to M) for the current die
        for (int k = 1; k <= M; k++) {
            // Only continue if the current sum is less than or equal to the target sum
            if (sum + k <= X) {
                cnt += solveMemo(M, N, X, i + 1, sum + k,dp);
            }
        }
        dp[i][sum]=cnt;
        return dp[i][sum];
    }

public:
    long long noOfWays(int M, int N, int X) {
       // return solve(M, N, X, 0, 0);
       vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
       return solveMemo(M, N, X, 0, 0,dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends