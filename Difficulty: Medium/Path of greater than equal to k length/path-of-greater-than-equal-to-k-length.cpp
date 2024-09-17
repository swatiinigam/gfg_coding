//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
public:
    bool dfs(int node, int dist, int k, vector<int>&vis, vector<vector<int>>&adj){
        if(dist >= k)   return true;
        vis[node]=1;
        for(int i=0; i<adj.size(); i++){
            if(adj[node][i]!=-1 && vis[i]==0){
                if(dfs(i, dist+adj[node][i], k, vis, adj))  return true;
            }
        }
        vis[node]=0;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) {
        vector<vector<int>>adj(V, vector<int>(V, -1));
        int i = 0;
        while(i<3*E){
            adj[a[i]][a[i+1]] = max(a[i+2], adj[a[i]][a[i+1]]);
            adj[a[i+1]][a[i]] = max(a[i+2], adj[a[i+1]][a[i]]);
            i+=3;
        }
        vector<int>vis(V, 0);
        
        return dfs(0, 0, k, vis, adj);
    } 
};



//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends