//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>>& heights) {
        vector<vector<int>> effort(rows, vector<int>(columns, INT_MAX));
        effort[0][0] = 0;
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq; // {effort, i, j}
        pq.push({0, 0, 0});
        
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int eff = curr[0], i = curr[1], j = curr[2];
            
            if (i == rows - 1 && j == columns - 1)
                return eff;
            
            for (auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if (ni >= 0 && ni < rows && nj >= 0 && nj < columns) {
                    int diff = max(effort[i][j], abs(heights[i][j] - heights[ni][nj]));
                    if (diff < effort[ni][nj]) {
                        effort[ni][nj] = diff;
                        pq.push({diff, ni, nj});
                    }
                }
            }
        }
        
        return -1; // This should not happen
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends