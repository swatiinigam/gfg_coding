//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <vector>
using namespace std;

class Solution {
private:
    int solve(vector<vector<int>>& matrix, int i, int j, int row, int col) {
        int ans = 0;
        // Check right coverage
        if (j + 1 < col && matrix[i][j] == 0 && matrix[i][j + 1] == 1) {
            ans += 1;
        }
        // Check left coverage
        if (j - 1 >= 0 && matrix[i][j] == 0 && matrix[i][j - 1] == 1) {
            ans += 1;
        }
        // Check up coverage
        if (i - 1 >= 0 && matrix[i][j] == 0 && matrix[i - 1][j] == 1) {
            ans += 1;
        }
        // Check down coverage
        if (i + 1 < row && matrix[i][j] == 0 && matrix[i + 1][j] == 1) {
            ans += 1;
        }
        return ans;
    }
    
public:
    int findCoverage(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int totalCoverage = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    totalCoverage += solve(matrix, i, j, row, col);
                }
            }
        }
        return totalCoverage;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends