//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{

public:
int findMinCost(string X, string Y, int costX, int costY)
{
    int m = X.size(), n = Y.size();
     int dp[m+1][n+1];
       for(int i=0;i<m+1;i++){
           for(int j=0;j<n+1;j++){
               if(i==0 || j==0) dp[i][j]=0;
           }
       }
       
       for(int i=1;i<m+1;i++){
           for(int j=1;j<n+1;j++){
               if(X[i-1]==Y[j-1]) dp[i][j]= 1+dp[i-1][j-1];
               else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
           }
       }
       return costX*(m-dp[m][n])+costY*(n-dp[m][n]);
}
 

};
	


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends