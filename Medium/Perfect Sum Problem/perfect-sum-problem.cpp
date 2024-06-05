//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
using namespace std;

class Solution{
    public:
    int mod = 1e9 + 7;
    int f(int ind, int sum, int arr[], vector<vector<int>> &dp){
        if(ind==0)
        {
            if(sum==0 && arr[0]==0) return 2;
            if(arr[0]==sum || sum==0) return 1;
            return 0;
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int notPick = f(ind-1,sum,arr,dp);
        int pick = 0;
        if(sum >= arr[ind]){
            pick = f(ind-1,sum-arr[ind],arr,dp);
        }
        
        return dp[ind][sum] = (pick + notPick)%mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> v(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,v);
    }
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends