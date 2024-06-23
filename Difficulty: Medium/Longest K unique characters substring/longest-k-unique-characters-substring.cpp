//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <unordered_map>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i = 0, j = 0;
        int maxLen = -1;
        int n = s.size();
        unordered_map<char, int> charCount;

        while (j < n) {
            charCount[s[j]]++;
            
            // If the number of unique characters exceeds k, shrink the window
            while (charCount.size() > k) {
                charCount[s[i]]--;
                if (charCount[s[i]] == 0) {
                    charCount.erase(s[i]);
                }
                i++;
            }

            // If the number of unique characters is exactly k, update maxLen
            if (charCount.size() == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }

        return maxLen;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends