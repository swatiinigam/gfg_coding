//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
     private:
         int mod=1e9+7;
       int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
           
           if(j>=s2.length())return 1;
           if(i>=s1.length())return 0;
           if(dp[i][j]!=-1)return dp[i][j];
           
           
           int op1=0;
           if(s1[i]==s2[j]){
               op1=solve(s1,s2,i+1,j+1,dp);
           }
           int op2=solve(s1,s2,i+1,j,dp);
           return dp[i][j]=(op1+op2)%mod;
           
           
           
       }
  public:
    int countWays(string s1, string s2) {
        // code here
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length(),-1));
        return solve(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends