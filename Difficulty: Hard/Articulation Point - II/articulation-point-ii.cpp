//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int timer = 0;

    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<bool>& isAP) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, isAP);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = true;
                }
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent == -1 && children > 1) {
            isAP[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), isAP(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, isAP);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (isAP[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends