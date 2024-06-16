//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int search(const std::string& pat, const std::string& txt) {
        int m = pat.size();
        int n = txt.size();
        
        if (m > n) return 0;

        std::vector<int> patFreq(26, 0);
        std::vector<int> windowFreq(26, 0);

        for (int i = 0; i < m; ++i) {
            patFreq[pat[i] - 'a']++;
            windowFreq[txt[i] - 'a']++;
        }

        int count = 0;
        if (patFreq == windowFreq) {
            count++;
        }

        for (int i = m; i < n; ++i) {
            windowFreq[txt[i] - 'a']++;
            windowFreq[txt[i - m] - 'a']--;

            if (patFreq == windowFreq) {
                count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends