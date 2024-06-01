//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	 private:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& adj, vector<vector<int>>& Transpose, stack<int> &st, bool reverse = false) {
        vis[node] = 1;
        for (auto it : (reverse ? Transpose[node] : adj[node])) {
            if (!vis[it]) {
                dfs(it, vis, adj, Transpose, st, reverse);
            }
        }
        if (!reverse) {
            st.push(node);
        }
    }

public:
    // Function to find the number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        // First DFS for topological sorting
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, adj, st); // Forward DFS
            }
        }

        vector<vector<int>> Transpose(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto &it : adj[i]) {
                Transpose[it].push_back(i);
            }
        }

        int count = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                count++;
                dfs(node, vis, adj, Transpose, st, true); // Reverse DFS
            }
        }

        return count;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends