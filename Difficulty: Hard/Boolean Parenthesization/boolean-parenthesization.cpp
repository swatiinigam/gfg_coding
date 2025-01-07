//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1003;
    int helper(int leftT, int rightT, int leftF, int rightF, char c, bool flag)
    {
        if(flag)
        {
            if(c == '|') return (leftT*rightT + leftT*rightF + leftF*rightT) % mod;
            if(c == '&') return (leftT*rightT) % mod;
            if(c == '^') return (leftT*rightF + leftF*rightT) % mod;
        }
        
        if(c == '|') return (leftF*rightF) % mod;
        if(c == '&') return (leftF*rightF + leftT*rightF + leftF*rightT) % mod;
        if(c == '^') return (leftT*rightT + leftF*rightF) % mod;
    }
    
    int solve(vector<vector<vector<int>>> &dp, int i, int j, string s, bool isTrue)
    {
        if(i == j)
        {
            if(isTrue) return s[i] == 'T';
            return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ans = 0;
        for(int k = i + 1; k < j; k += 2)
        {
            int leftT = solve(dp,i,k-1,s,true);
            int rightT = solve(dp,k+1,j,s,true);
            int leftF = solve(dp,i,k-1,s,false);
            int rightF = solve(dp,k+1,j,s,false);
            
            
            int temp = helper(leftT,rightT,leftF,rightF,s[k], isTrue);
            ans = (ans + temp) % mod;
        }
        
        return dp[i][j][isTrue] = ans;
    }
public:
    int countWays(int n, string s){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,-1)));
        return solve(dp,0,s.length()-1,s,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends