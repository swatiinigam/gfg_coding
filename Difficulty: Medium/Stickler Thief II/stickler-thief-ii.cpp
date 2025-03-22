//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i, vector<int>&a, int n, vector<int>&dp){
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int p = f(i + 2, a, n, dp) + a[i];
        int q = f(i + 1, a, n, dp);
        return dp[i] = max(p, q);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n, -1);
        return f(0, arr, n, dp);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        vector<int>a, b;
        
        for(int i = 0; i < arr.size(); i++){
            if(i != 0) a.push_back(arr[i]);
            if(i != arr.size() - 1) b.push_back(arr[i]);
        }
        return max(findMaxSum(a), findMaxSum(b));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends