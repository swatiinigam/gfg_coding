//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int> > adj[n+1];
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> parent (n+1);
        vector<int> short_dist (n+1,1e9);
        set<pair<int,int> > st;
        st.insert({0,1});
        short_dist[1] = 0;
        for(int i=0; i<=n; i++) parent[i] = i;
        
        while(!st.empty()){
            auto t = *(st.begin());
            int dist = t.first;
            int node = t.second;
            st.erase(t);
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                
                if( dist + weight < short_dist[adjNode]){
                    if(short_dist[adjNode]!=1e9)
                        st.erase({short_dist[adjNode], adjNode});
                    short_dist[adjNode] = dist + weight;
                    parent[adjNode] = node;
                    st.insert({short_dist[adjNode],adjNode});
                }
            }
        }
        
        if(short_dist[n] == 1e9) return {-1};
        
        vector<int> ans;
        int node = n;
        while(parent[node]!=node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        ans.push_back(short_dist[n]);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends