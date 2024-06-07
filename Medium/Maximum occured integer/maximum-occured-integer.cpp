//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // l and r are input arrays
    // maxx: maximum in r[]
    // n: size of the array
    // arr[]: declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
        // Initialize the array with size maxx + 2 (to handle r[i] + 1)
        vector<int> arr(maxx + 2, 0);

        // Applying the prefix sum technique
        for (int i = 0; i < n; ++i) {
            arr[l[i]]++;          // Start of the range
            arr[r[i] + 1]--;      // End of the range (one past r[i])
        }

        // Calculate the prefix sums and find the maximum
        int max_occurrence = arr[0];
        int result = 0;
        for (int i = 1; i <= maxx; ++i) {
            arr[i] += arr[i - 1]; // Prefix sum array
            if (arr[i] > max_occurrence) {
                max_occurrence = arr[i];
                result = i;
            }
        }

        return result;
    }
};



//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends