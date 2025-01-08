//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int n, int m, vector<vector<int>> grid) 
	{ 
	   vector<vector<int>> dp(n,vector<int>(m));
    dp[n-1][m-1] = (grid[n-1][m-1] > 0 ? 0 : -grid[n-1][m-1] + 1);
    for(int i=m-2;i>=0;i--){
        if(grid[n-1][i] > dp[n-1][i+1]){
                dp[n-1][i] = 0;
        }else{
            if(dp[n-1][i+1] == 0){
                dp[n-1][i] = 1 - grid[n-1][i];
            }else{
                dp[n-1][i] = dp[n-1][i+1] - grid[n-1][i];
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        if(grid[i][m-1] > dp[i+1][m-1]){
                dp[i][m-1] = 0;
        }else{
            if(dp[i+1][m-1] == 0){
                dp[i][m-1] = 1 - grid[i][m-1];
            }else{
                dp[i][m-1] = dp[i+1][m-1] - grid[i][m-1];
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            int temp = min(dp[i+1][j],dp[i][j+1]);
            if(grid[i][j] > temp){
                dp[i][j] = 0;
            }else{
                if(temp == 0){
                    dp[i][j] = 1 - grid[i][j];
                }else{
                    dp[i][j] = temp - grid[i][j];
                }
            }
        }
    }
    return (dp[0][0] == 0) ? 1 : dp[0][0];
	}
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends