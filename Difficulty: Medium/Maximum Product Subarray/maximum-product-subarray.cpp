//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        if (n == 0) return 0;
        
        long long maxProduct = arr[0];
        long long minProduct = arr[0];
        long long result = arr[0];
        
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                // Swap maxProduct and minProduct when a negative number is encountered
                swap(maxProduct, minProduct);
            }
            
            // Calculate the max and min product subarrays ending at the current index
            maxProduct = max((long long)arr[i], maxProduct * arr[i]);
            minProduct = min((long long)arr[i], minProduct * arr[i]);
            
            // Update the result with the maximum product found so far
            result = max(result, maxProduct);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends