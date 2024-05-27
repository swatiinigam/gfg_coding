//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void solve(vector<vector<int>>& m, int n, int i, int j, vector<string>& paths, string path, vector<vector<bool>>& vis) {
        // Base case: Reached bottom-right corner
        if (i == n - 1 && j == n - 1) {
            paths.push_back(path);
            return;
        }
        
        // Boundary checks and move validity
        // Down move
        if (i + 1 < n && m[i + 1][j] == 1 && !vis[i + 1][j]) {
            vis[i + 1][j] = true;
            solve(m, n, i + 1, j, paths, path + "D", vis);
            vis[i + 1][j] = false;
        }
        
        // Up move
        if (i - 1 >= 0 && m[i - 1][j] == 1 && !vis[i - 1][j]) {
            vis[i - 1][j] = true;
            solve(m, n, i - 1, j, paths, path + "U", vis);
            vis[i - 1][j] = false;
        }
        
        // Right move
        if (j + 1 < n && m[i][j + 1] == 1 && !vis[i][j + 1]) {
            vis[i][j + 1] = true;
            solve(m, n, i, j + 1, paths, path + "R", vis);
            vis[i][j + 1] = false;
        }
        
        // Left move
        if (j - 1 >= 0 && m[i][j - 1] == 1 && !vis[i][j - 1]) {
            vis[i][j - 1] = true;
            solve(m, n, i, j - 1, paths, path + "L", vis);
            vis[i][j - 1] = false;
        }
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> paths;
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return paths; // If start or end is blocked

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        solve(m, n, 0, 0, paths, "", vis);
        
        return paths;
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