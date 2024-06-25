//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        // Reduce k to the effective number of rotations needed
        k = k % col;
        
        for (int i = 0; i < row; ++i) {
            // Rotate each row to the left by k steps
            vector<int> newRow(col);
            for (int j = 0; j < col; ++j) {
                newRow[j] = mat[i][(j + k) % col];
            }
            mat[i] = newRow;
        }
        
        return mat;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends