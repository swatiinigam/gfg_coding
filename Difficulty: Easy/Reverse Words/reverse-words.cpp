//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        stack<string> s;
        string st = "";

        // Traverse the string character by character
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') {
                // When a dot is found, push the current word onto the stack
                s.push(st);
                st = ""; // Reset current word
            } else {
                // Append character to the current word
                st += str[i];
            }
        }
        
        // Push the last word onto the stack
        s.push(st);

        // Construct the final answer
        string ans = "";
        while (!s.empty()) {
            ans += s.top(); // Add the top word from the stack
            s.pop();
            if (!s.empty()) {
                ans += "."; // Add a dot if there are more words
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends