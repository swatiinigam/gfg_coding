//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long int PowMod(long long int x, long long int n, long long int M) {
        long long int result = 1;
        x = x % M;  // Update x if it is more than or equal to M

        if (x == 0) return 0;  // In case x is divisible by M

        while (n > 0) {
            // If n is odd, multiply x with result
            if (n % 2 == 1) {
                result = (result * x) % M;
            }

            // n must be even now
            n = n >> 1;  // n = n / 2
            x = (x * x) % M;  // Change x to x^2
        }

        return result;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends