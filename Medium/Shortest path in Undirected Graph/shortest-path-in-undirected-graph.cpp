//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //make a adjlist
        vector<vector<int>>adj(N);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        //bfs
        queue<int>q;
        vector<int>dis(N,INT_MAX);
        dis[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto neigh: adj[curr]){
                if(dis[curr]+1<dis[neigh]){
                   dis[neigh]=dis[curr]+1;
                   q.push(neigh);
                }
            }
            
        }
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        return dis;
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