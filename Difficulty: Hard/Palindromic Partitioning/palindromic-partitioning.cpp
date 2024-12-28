//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(string str){
    if(str.length()==1){
        return true;
    }
    int low=0;
    int high=str.length()-1;
    while(low<high){
        if(str[low]!=str[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}
int palindromicPartition(string str)
    {
        int n=str.length();
        vector<int>dp(n+1,-1);
        dp[n]=0;
        for(int ind=n-1;ind>=0;ind--){
            int mini=INT_MAX;
            for(int i=1;i<=n-ind;i++){
        if(isValid(str.substr(ind,i))){
            mini=min(mini,1+dp[ind+i]);
        }
    }
    dp[ind]=mini;
        }
        return dp[0]-1;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends