//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Helper function to check if we can place k cows with at least minDist distance between them
    bool canPlaceCows(int minDist, int k, vector<int> &stalls) {
        int cowsPlaced = 1; // Place the first cow in the first stall
        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= minDist) {
                cowsPlaced++;
                lastPosition = stalls[i];
                if (cowsPlaced == k) {
                    return true;
                }
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Sort the stall positions
        sort(stalls.begin(), stalls.end());

        // Binary search on the distance
        int low = 1; // Minimum possible distance
        int high = stalls[n-1] - stalls[0]; // Maximum possible distance
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(mid, k, stalls)) {
                result = mid; // mid is a valid minimum distance
                low = mid + 1; // Try for a larger minimum distance
            } else {
                high = mid - 1; // Try for a smaller minimum distance
            }
        }

        return result; // The maximum feasible minimum distance
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends