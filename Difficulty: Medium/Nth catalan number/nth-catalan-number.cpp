//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the Nth Catalan number modulo 1e9+7.
    int findCatalan(int N) {
        const int MOD = 1e9 + 7;

        // Create a vector to store the Catalan numbers.
        vector<int> catalan(N + 1, 0);

        // Base case: Catalan number for 0 is 1.
        catalan[0] = 1;

        // Calculate Catalan numbers using dynamic programming.
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] = (catalan[i] + (long long)catalan[j] * catalan[i - j - 1]) % MOD;
            }
        }

        return catalan[N];
    }
};




//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends