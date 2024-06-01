//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string oddEven(string s) {
        // To count frequency
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // To keep track of distinct characters for x and y
        unordered_set<char> x_set;
        unordered_set<char> y_set;

        for (auto &entry : freq) {
            char ch = entry.first;
            int count = entry.second;
            int position = ch - 'a' + 1; // 1-based index for alphabet position

            if (position % 2 == 0 && count % 2 == 0) {
                // Even position and even frequency
                x_set.insert(ch);
            } else if (position % 2 == 1 && count % 2 == 1) {
                // Odd position and odd frequency
                y_set.insert(ch);
            }
        }

        int x = x_set.size();
        int y = y_set.size();

        int sum = x + y;
        if (sum % 2 == 0) {
            return "EVEN";
        } else {
            return "ODD";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends