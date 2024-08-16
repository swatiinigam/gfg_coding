//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{   
    private:
    int solve(int n, int x, int y, int z, int length, vector<int>& dp) {
        if(length == 0) {
            return 0;  // If we have exactly 0 length left, no more cuts needed
        }
        if(length < 0) {
            return INT_MIN;  // If the length is negative, it's an invalid case
        }
        if(dp[length] != -1) {
            return dp[length];  // If already computed, return the stored value
        }

        // Recursive calls to try cutting the rod by lengths x, y, and z
        int cutX = solve(n, x, y, z, length - x, dp);
        int cutY = solve(n, x, y, z, length - y, dp);
        int cutZ = solve(n, x, y, z, length - z, dp);

        // Take the maximum cuts and add 1 because we made a cut if it is valid
        int maxCuts = max({cutX, cutY, cutZ});
        dp[length] = (maxCuts == INT_MIN) ? INT_MIN : maxCuts + 1;

        return dp[length];
    }

    public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        int res = solve(n, x, y, z, n, dp);
        
        return res < 0 ? 0 : res;
    }
};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends