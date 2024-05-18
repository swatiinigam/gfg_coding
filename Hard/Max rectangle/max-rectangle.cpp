//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define MAX 1000

class Solution {
private:
    int maxHistArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);  // Append a zero to handle the remaining elements in the stack
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, h * width);
            }
            s.push(i);
        }
        heights.pop_back();  // Remove the appended zero
        return max_area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> height(m, 0);
        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Update the height of histogram
                height[j] = M[i][j] == 0 ? 0 : height[j] + 1;
            }
            // Find the maximum area for this row's histogram
            max_area = max(max_area, maxHistArea(height));
        }

        return max_area;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends