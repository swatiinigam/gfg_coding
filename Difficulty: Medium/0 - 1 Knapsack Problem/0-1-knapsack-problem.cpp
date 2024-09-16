//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Recursive function with memoization
    int knapSackRec(int index, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        // Base cases
        if (index >= wt.size() || W == 0) return 0;

        // If the value is already computed
        if (dp[index][W] != -1) return dp[index][W];

        // If weight of the current item is more than the knapsack capacity
        if (wt[index] > W) {
            return dp[index][W] = knapSackRec(index + 1, W, wt, val, dp);
        } else {
            // Return the maximum of including the item or excluding it
            int includeItem = val[index] + knapSackRec(index + 1, W - wt[index], wt, val, dp);
            int excludeItem = knapSackRec(index + 1, W, wt, val, dp);
            return dp[index][W] = max(includeItem, excludeItem);
        }
    }
    
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size(); // Number of items
        vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // DP table with -1 indicating uncomputed values
        
        return knapSackRec(0, W, wt, val, dp);
    }
};



//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends