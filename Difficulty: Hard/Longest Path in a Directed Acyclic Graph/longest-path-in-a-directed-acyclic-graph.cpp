//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Utility function for topological sorting using DFS
    void topologicalSort(int node, vector<bool> &visited, stack<int> &Stack, vector<vector<pair<int, int>>> &adj) {
        visited[node] = true;
        for (auto &neighbor : adj[node]) {
            int v = neighbor.first;
            if (!visited[v]) {
                topologicalSort(v, visited, Stack, adj);
            }
        }
        Stack.push(node);
    }

    vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src) {
        // Step 1: Create adjacency list for the graph
        vector<vector<pair<int, int>>> adj(v);
        for (int i = 0; i < e; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
        }

        // Step 2: Topological Sort
        stack<int> Stack;
        vector<bool> visited(v, false);
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                topologicalSort(i, visited, Stack, adj);
            }
        }

        // Step 3: Initialize distances to all vertices as INT_MIN
        vector<int> dist(v, INT_MIN);
        dist[src] = 0;

        // Step 4: Process vertices in topological order
        while (!Stack.empty()) {
            int u = Stack.top();
            Stack.pop();

            // Update distances of all adjacent vertices of the popped vertex
            if (dist[u] != INT_MIN) {
                for (auto &neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[v] < dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist;
    }
};


//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends