//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
    // Get the lower nibble
    int lowerNibble = n & 0x0F; // 0x0F is 00001111 in binary
    // Get the upper nibble
    int upperNibble = (n & 0xF0) >> 4; // 0xF0 is 11110000 in binary
    
    // Swap the nibbles and combine them
    int result = (lowerNibble << 4) | upperNibble;
    
    return result;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends