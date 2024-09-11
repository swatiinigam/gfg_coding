//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int mini =prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            int diff =prices[i]-mini;
            profit= max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends