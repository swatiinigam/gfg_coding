//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
    public:
    // Function to find the sum of weights of the edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to pick the minimum weight edge
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize key values as infinite
        vector<int> key(V, INT_MAX);
        // To keep track of nodes included in the MST
        vector<bool> inMST(V, false);

        // Start from the first node (0)
        key[0] = 0;
        pq.push({0, 0});  // (weight, vertex)

        int total_weight = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            // Include the node in MST
            inMST[u] = true;
            total_weight += key[u];

            // Traverse all adjacent nodes
            for (auto &neighbor : adj[u]) {
                int v = neighbor[0];
                int weight = neighbor[1];

                // If v is not in MST and weight of (u,v) is smaller than current key of v
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        return total_weight;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends