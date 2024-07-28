//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
public:
    void dfs1(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<int> transpose[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : transpose[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, transpose, visited);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[]) {
        stack<int> st;
        vector<bool> visited(V, false);

        // Step 1: Order the nodes in decreasing order of finishing times
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }

        // Step 2: Transpose the graph
        vector<int> transpose[V];
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                transpose[neighbor].push_back(i);
            }
        }

        // Step 3: Perform DFS on the transposed graph in the order of the stack
        fill(visited.begin(), visited.end(), false);
        int count = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                dfs2(node, transpose, visited);
                count++;
            }
        }
        return count;
    }

    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Find the number of SCCs in the original graph
        int originalSCCCount = kosaraju(V, adj);

        // Remove edge (c, d) from the graph
        for (auto it = adj[c].begin(); it != adj[c].end(); it++) {
            if (*it == d) {
                adj[c].erase(it);
                break;
            }
        }

        // Find the number of SCCs in the modified graph
        int newSCCCount = kosaraju(V, adj);

        // Re-add the edge (c, d) to restore the original graph
        adj[c].push_back(d);

        // If the number of SCCs has increased, then (c, d) is a bridge
        return (newSCCCount > originalSCCCount) ? 1 : 0;
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