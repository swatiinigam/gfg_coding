//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


#define MOD 1000000007

class Solution {
public:
    int permutationCoeff(int n, int k) {
        if (k > n) {
            return 0;
        }
        
        // Initialize result
        long long result = 1;
        
        // Compute P(n, k) iteratively
        for (int i = 0; i < k; ++i) {
            result = (result * (n - i)) % MOD;
        }
        
        return result;
    }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Solution ob;
        int ans = ob.permutationCoeff(n,k);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends