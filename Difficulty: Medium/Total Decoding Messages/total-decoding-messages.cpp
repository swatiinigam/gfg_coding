//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
	    int solve(int index, int n, string str,vector<int>&dp)
	    {
	        if(index>=n)return 1;
	        if(dp[index]!=-1)return dp[index]%mod;
	        string temp="";
	        int ans=0;
	        for(int i=index; i<n; i++)
	        {
	            temp+=str[i];
	            int a=stoi(temp);
	            if(a>=1 and a<=26)
	            {
	                ans+=solve(i+1,n,str,dp)%mod;
	            }
	            else
	            {
	                break;
	            }
	        }
	        return dp[index]= ans%mod;
	    }
		int countWays(string str)
		{
		    int n=str.length();
		    vector<int>dp(n,-1);
		    int ans=solve(0,n,str,dp)%mod;
		    return ans;
		}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.countWays(s);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends