//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isCyclicUtil(int v, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;

        for (int u : adj[v]) {
            if (!visited[u]) {
                if (isCyclicUtil(u, adj, visited, recStack))
                    return true;
            } else if (recStack[u]) {
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (isCyclicUtil(i, adj, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

  

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends