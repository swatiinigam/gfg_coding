//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        unordered_map<char,int>mp;
        int ans=0;
        for(char ch:s){
            int val=mp[ch];
            mp[ch]=val+1;
            ans+=mp[ch];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends