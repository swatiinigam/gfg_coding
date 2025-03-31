//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        vector<int>dp(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            int index=s[i]-'a';
            dp[index]=i;
        }
        int count=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int index=s[i]-'a';
            maxi=max(maxi,dp[index]);
            if(maxi<=i){
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends