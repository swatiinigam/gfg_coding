//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //using topological sort
        
        vector<int>indegree(V,0);
        queue<int>q;
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        
        for(int i=0;i<V;i++){
               if(indegree[i]==0){
                   q.push(i);
               }
        }
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto neigh:adj[curr]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
            
        }
        if(ans.size()==V){
            return false;
        }
        else{
            return true;
        }
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