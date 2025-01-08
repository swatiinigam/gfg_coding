//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int func(int k, int st, int sum){
        if(k == 0) return sum == 0; 
        if(dp[k][st][sum] != -1) return dp[k][st][sum];
        int sz = sum / k, ans = 0;
        for(int i = st; st <= sz and i <= sum; i++) ans += func(k-1, i, sum - i);
        return dp[k][st][sum] = ans;
    }
    int countWaystoDivide(int N, int K) { 
        dp.resize(K, vector<vector<int>>(N+1, vector<int>(N+1, -1)));
        int sz = N / K, ans = 0;
        for(int i = 1; i <= sz; i++) ans += func(K-1, i, N-i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends