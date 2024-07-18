//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int alternatingMaxLength(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        // Length of longest alternating subsequence ending at index i
        int maxLength = 1;

        // up[i] stores the length of the longest alternating subsequence ending at i with arr[i-1] < arr[i]
        // down[i] stores the length of the longest alternating subsequence ending at i with arr[i-1] > arr[i]
        int up = 1, down = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                up = down + 1;
            } else if (arr[i] < arr[i - 1]) {
                down = up + 1;
            }
            // Update the maximum length found so far
            maxLength = std::max(maxLength, std::max(up, down));
        }

        return maxLength;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends