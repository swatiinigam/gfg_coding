//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int components = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, adj, visited);
                components++;
            }
        }
        return components;
    }

    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Count components before removing the edge
        int initialComponents = countComponents(V, adj);

        // Remove the edge (c, d)
        auto it = find(adj[c].begin(), adj[c].end(), d);
        if (it != adj[c].end()) adj[c].erase(it);
        
        it = find(adj[d].begin(), adj[d].end(), c);
        if (it != adj[d].end()) adj[d].erase(it);

        // Count components after removing the edge
        int componentsAfterRemoval = countComponents(V, adj);

        // Add the edge back to restore original graph
        adj[c].push_back(d);
        adj[d].push_back(c);

        // If components increased, the edge is a bridge
        if (componentsAfterRemoval > initialComponents) {
            return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends