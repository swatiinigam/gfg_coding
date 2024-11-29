//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    
    
    int kadane(vector<int>& a) {
        int mx = a[0];
        int cur = a[0];
        for(int i = 1; i < a.size(); i++) {
            cur = max(a[i], cur + a[i]);
            mx = max(mx, cur);
        }
        return mx;
    }
    
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int max1 = kadane(arr);
        if(max1 < 0) 
            return max1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            arr[i] = -arr[i];
        }
        int min1 = kadane(arr);
        int max2 = sum + min1;
        return max(max2, max1);

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends