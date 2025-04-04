//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int index,unordered_map<int,bool> &visit,vector<vector<int>> adj){
    unordered_map<int,int> parent;

    parent[index] = -1;

    queue<int> q;
    q.push(index);
    visit[index] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(auto i : adj[f]){
            if((visit[i] == true )&& (i != parent[f])){
                return true;
            }else if(visit[i] == 0){
                q.push(i);
                visit[i] = true;
                parent[i] = f;
            }
        }
    }

    return false;
}
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        unordered_map<int,bool> visit;

        for(int i = 0;i<V;i++){
        if(visit[i] == 0){
            bool ans = solve(i,visit,adj);
            if(ans == 1){
                return true;
                }
            }
        }

        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends