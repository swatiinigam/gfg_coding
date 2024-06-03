//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define ll long long
#define mod 1000000007

class Solution {
public:
    ll add(ll a, ll b) {
        return (a % mod + b % mod) % mod;
    }

    ll mul(ll a, ll b) {
        return (a % mod * 1LL * b % mod) % mod;
    }

    long long countWays(int n, int k) {
        ll dp[2];
        dp[0] = k;
        dp[1] = mul(k, k);
        for (int i = 2; i < n; i++) {
            ll same = mul(dp[(i-1)&1], k - 1);
            ll diff = mul(dp[(i-2)&1], k - 1);
            dp[i&1] = add(same, diff);
        }
        return dp[(n-1)&1];
    }
};





//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends