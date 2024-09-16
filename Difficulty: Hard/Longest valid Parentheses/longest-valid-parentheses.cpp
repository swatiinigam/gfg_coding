//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int maxLength(string& str) {
        stack<int> stk;
        stk.push(-1); // Initialize stack with -1 to handle edge case
        
        int max_len = 0; // To keep track of the maximum length of valid parentheses
        
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                // Push the index of the '(' onto the stack
                stk.push(i);
            } else { // str[i] == ')'
                // Pop the top index from the stack
                stk.pop();
                
                if (stk.empty()) {
                    // If the stack is empty, push the current index onto the stack
                    stk.push(i);
                } else {
                    // Calculate the length of the current valid substring
                    max_len = max(max_len, i - stk.top());
                }
            }
        }
        
        return max_len;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends