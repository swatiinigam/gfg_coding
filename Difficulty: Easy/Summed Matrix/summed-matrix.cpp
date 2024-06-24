//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // Calculate the valid range for i
        long long start = std::max(1LL, q - n);
        long long end = std::min(n, q - 1);
        
        // If the range is valid, calculate the number of elements in this range
        if (start <= end) {
            return end - start + 1;
        } else {
            return 0;
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends