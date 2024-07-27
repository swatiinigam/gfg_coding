//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    
    
  private:
  
  bool dfs(int node,vector<int>adj[],vector<bool>&vis,vector<bool>&resvis){
      vis[node]=true;
      resvis[node]=true;
      for(auto it: adj[node]){
          if(!vis[it]){
              if(dfs(it,adj,vis,resvis)){
                  return true;
              }
          }
          else if(resvis[it]){
              return true;
          }
      }
      resvis[node]=false;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false);
        vector<bool>resvis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,resvis)){
                    return true;
                }
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