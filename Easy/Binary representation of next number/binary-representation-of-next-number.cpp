//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string binaryNextNumber(string s) {
        int n = s.size();
        int carry = 1;  // Start with carry = 1 since we are adding 1 to the number
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
                carry = 0;
                break;
            }
        }
        
        if (carry == 1) {
            s = '1' + s;
        }

        // Remove leading zeroes
        size_t pos = s.find_first_not_of('0');
        if (pos != string::npos) {
            s = s.substr(pos);
        } else {
            s = "0";
        }
        
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends