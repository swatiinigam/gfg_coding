//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int help(int a[],int n,int k,int i,int buy,vector<vector<vector<int>>>& memo){
        if(i>=n or k<0) return 0;
        if(memo[i][k][buy]!=-1) return memo[i][k][buy];
        int sell=0,brought=0;
        if(buy){
            sell = max(a[i]+help(a,n,k,i+1,0,memo),help(a,n,k,i+1,1,memo));
        }
        else{
            brought = max(-a[i]+help(a,n,k-1,i+1,1,memo),help(a,n,k,i+1,0,memo));
        }
        return memo[i][k][buy] = max({sell,brought});
    }
    int maxProfit(int k, int n, int a[]) {
        // code here
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(k+1,vector<int>(3,-1)));
        return help(a,n,k,0,0,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends