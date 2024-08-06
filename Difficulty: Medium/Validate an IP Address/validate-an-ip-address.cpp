//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

class Solution {
public:
    int isValid(std::string str) {
        // Splitting the string by dots
        std::vector<std::string> segments;
        std::stringstream ss(str);
        std::string segment;
        
        while (std::getline(ss, segment, '.')) {
            segments.push_back(segment);
        }
        
        // Check if the number of segments is exactly 4
        if (segments.size() != 4) {
            return 0;
        }
        
        for (const auto& s : segments) {
            // Check if each segment is a valid number
            if (s.empty() || s.size() > 3 || (s[0] == '0' && s.size() > 1)) {
                return 0;
            }
            
            for (char c : s) {
                if (!isdigit(c)) {
                    return 0;
                }
            }
            
            int num = std::stoi(s);
            if (num < 0 || num > 255) {
                return 0;
            }
        }
        
        return 1; // All segments are valid
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends