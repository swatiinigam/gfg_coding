//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
private:
    void topologicalSort(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis, stack<int>& topoOrder) {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                topologicalSort(it.first, adj, vis, topoOrder);
            }
        }
        topoOrder.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list with weights
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Step 2: Perform topological sort
        stack<int> topoOrder;
        vector<bool> vis(N, false);
        for (int i = 0; i < N; ++i) {
            if (!vis[i]) {
                topologicalSort(i, adj, vis, topoOrder);
            }
        }

        // Step 3: Initialize distances
        vector<int> dist(N, INT_MAX);
        dist[0] = 0; // Distance to the source node (node 0)

        // Step 4: Relax edges in topological order
        while (!topoOrder.empty()) {
            int node = topoOrder.top();
            topoOrder.pop();
            
            if (dist[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int neighbor = it.first;
                    int weight = it.second;
                    if (dist[node] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[node] + weight;
                    }
                }
            }
        }

        // Replace INT_MAX with -1 for unreachable nodes
        for (int &d : dist) {
            if (d == INT_MAX) {
                d = -1;
            }
        }

        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends