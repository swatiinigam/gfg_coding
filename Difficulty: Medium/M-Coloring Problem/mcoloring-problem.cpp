//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Helper function to check if it's safe to color the current node with the given color
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
        for (int k = 0; k < n; k++) {
            // Check if any adjacent node has the same color
            if (graph[node][k] && color[k] == col) {
                return false; // Not safe to color this node with col
            }
        }
        return true; // Safe to color this node with col
    }

    // Recursive function to try coloring the graph using backtracking
    bool graphColoringUtil(int node, int color[], bool graph[101][101], int m, int n) {
        // If all nodes are colored, return true
        if (node == n) {
            return true;
        }

        // Try different colors for the node
        for (int col = 1; col <= m; col++) {
            // Check if it's safe to color the node with color 'col'
            if (isSafe(node, color, graph, n, col)) {
                color[node] = col; // Assign color 'col' to node

                // Recursively color the next node
                if (graphColoringUtil(node + 1, color, graph, m, n)) {
                    return true; // If successful, return true
                }

                color[node] = 0; // Backtrack: Undo the color assignment
            }
        }

        return false; // If no color can be assigned to this node, return false
    }

    // Main function to determine if the graph can be colored with at most 'm' colors
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[101] = {0}; // Initialize color array with 0 (no color assigned)

        // Start coloring the graph from the first node
        if (graphColoringUtil(0, color, graph, m, n)) {
            return true; // If successful, return true
        }

        return false; // If not, return false
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends