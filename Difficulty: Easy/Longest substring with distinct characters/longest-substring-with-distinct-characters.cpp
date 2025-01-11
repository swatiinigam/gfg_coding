//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) 
    {
        int ans = INT_MIN;
        int l = 0;
        int r = 0;
        int n = s.size();
        int hash[256];
        for(int i = 0; i < 256; i++)
        {
            hash[i] = -1;
        }
        
        while( r < n)
        {
            if(hash[s[r]] != -1 && hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
            ans = max(ans, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends