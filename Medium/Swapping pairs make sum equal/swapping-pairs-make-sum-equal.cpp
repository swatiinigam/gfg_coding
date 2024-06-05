//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int suma = 0, sumb = 0;
        for (int i = 0; i < n; i++) {
            suma += a[i];
        }
        for (int i = 0; i < m; i++) {
            sumb += b[i];
        }

        int diff = suma - sumb;

        // If the difference is not even, there's no solution
        if (diff % 2 != 0) {
            return -1;
        }

        // Calculate the target difference each element needs to satisfy
        diff /= 2;

        unordered_set<int> setB;
        for (int i = 0; i < m; i++) {
            setB.insert(b[i]);
        }

        for (int i = 0; i < n; i++) {
            int target = a[i] - diff;
            if (setB.find(target) != setB.end()) {
                return 1;  // Pair found
            }
        }

        return -1;  // No such pair exists
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends