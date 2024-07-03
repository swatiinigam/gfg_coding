//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
    // Helper function to perform DFS and check for cycles
    bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &graph) {
        vis[node] = 1;

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                if (!dfs(neighbor, node, vis, graph)) {
                    return false;
                }
            } else if (neighbor != parent) {
                // If the neighbor is visited and it's not the parent, there's a cycle
                return false;
            }
        }
        return true;
    }
    
  public:
    int isTree(int n, int m, vector<vector<int>> &edges) {
        // A tree must have exactly n-1 edges
        if (m != n - 1) {
            return 0;
        }
        
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        
        // Check if the graph is connected and acyclic using DFS
        if (!dfs(0, -1, vis, graph)) {
            return 0;
        }
        
        // Ensure all nodes are visited (graph is connected)
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return 0;
            }
        }
        
        return 1;  // The graph is a tree
    }
};


// Example usage



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends