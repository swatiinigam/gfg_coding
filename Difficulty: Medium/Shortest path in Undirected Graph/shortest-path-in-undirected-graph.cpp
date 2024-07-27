//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
private:
    void bfs(vector<vector<int>>& adj, int N, int src, queue<int>& q, vector<bool>& vis, unordered_map<int, int>& parent) {
        q.push(src);
        vis[src] = true;
        parent[src] = -1;  // No parent for the source node
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            
            for (auto it : adj[front]) {
                if (!vis[it]) {
                    vis[it] = true;
                    parent[it] = front;
                    q.push(it);
                }
            }
        }
    }

public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<vector<int>> adj(N);
        queue<int> q;
        unordered_map<int, int> parent;
        vector<bool> vis(N, false);
        
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(adj, N, src, q, vis, parent);
        
        vector<int> path;
        for (int i = 0; i < N; ++i) {
            if (i == src) {
                path.push_back(0);
            } else if (!vis[i]) {
                path.push_back(-1);  // Node is not reachable
            } else {
                int length = 0;
                int current = i;
                while (current != -1) {
                    current = parent[current];
                    length++;
                }
                path.push_back(length - 1);  // Length of the path from source to node i
            }
        }

        return path;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends