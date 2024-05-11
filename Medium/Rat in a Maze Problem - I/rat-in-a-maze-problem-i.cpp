//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
private:
    void solve(vector<vector<int>> &m, int n, int row, int col, int i, int j, string path, vector<string> &result, vector<vector<bool>> &vis) {
        if (i < 0 || i >= row || j < 0 || j >= col || m[i][j] == 0 || vis[i][j]) {
            return;
        }
        if (i == row - 1 && j == col - 1) {
            result.push_back(path);
            return;
        }
        vis[i][j] = true;
        solve(m, n, row, col, i, j + 1, path + 'R', result, vis);
        solve(m, n, row, col, i + 1, j, path + 'D', result, vis);
        solve(m, n, row, col, i, j - 1, path + 'L', result, vis);
        solve(m, n, row, col, i - 1, j, path + 'U', result, vis);
        vis[i][j] = false;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if (m[0][0] == 1) {
            solve(m, n, n, n, 0, 0, "", result, vis);
        }
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends