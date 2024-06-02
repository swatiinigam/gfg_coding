//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

#include <vector>
using namespace std;

class Solution {
private:
    int solve(int arr[], int i, int n, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        // The thief can either steal from the current house and skip the next one,
        // or skip the current house and move to the next one.
        int stealCurrent = arr[i] + solve(arr, i + 2, n, dp);
        int skipCurrent = solve(arr, i + 1, n, dp);
        dp[i] = max(stealCurrent, skipCurrent);
        return dp[i];
    }

public:
    int FindMaxSum(int arr[], int n) {
        // Vector to store the maximum money thief can get up to ith house
        vector<int> dp(n, -1);
        // Start solving from the first house
        return solve(arr, 0, n, dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends