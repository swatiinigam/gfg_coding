//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
using namespace std;

class Solution {
private:
    bool solve(int node, int V, vector<int> adj[], int parent, vector<bool>& vis) {
        vis[node] = true;
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                if (solve(neigh, V, adj, node, vis))
                    return true; // Cycle detected
            } else if (neigh != parent) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle detected
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (solve(i, V, adj, -1, vis)) {
                    return true; // Cycle detected
                }
            }
        }
        return false; // No cycle detected
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends