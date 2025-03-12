//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  private:
    int solve(vector<int> &cost, int i, int n, vector<int> &dp){
        if(i==n-1){
            return cost[n-1];
        }
        if(i== n-2){
            return  cost[n-2];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]= cost[i] +min(solve(cost, i+1, n, dp), solve(cost, i+2, n, dp));
        return dp[i];
    }
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int i=0;
        vector<int> dp(n+1, -1);
        
        int maxi= min(solve(cost, i, n, dp), solve(cost, i+1, n, dp));
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends