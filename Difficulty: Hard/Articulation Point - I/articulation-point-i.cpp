//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int timer=0;
    void dfs(vector<int> &low,vector<int> &time,int node,int parent,vector<int> adj[],vector<int> &vis,set<int>&answer)
    {
         vis[node]=1;
         timer++;
         time[node]=timer;
         low[node]=timer;
         int child=0;
         for(auto x:adj[node])
         {
            if(x==parent)
            continue;
            if(!vis[x])
            {
                 dfs(low,time,x,node,adj,vis,answer);
                 low[node]=min(low[x],low[node]);
                 if(low[x]>=time[node] && parent!=-1)
                 {
                  answer.insert(node);  
                 }
                 child++;
            }
            else
            {
                low[node]=min(low[node],time[x]);
            }
         }
         if(parent==-1 && child>1)
         answer.insert(node);
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> time(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        vector<int> ans;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(low,time,i,-1,adj,vis,s);
            }
        }
        if(s.size()==0)
        return {-1};
        for(auto x:s)
        {
            ans.push_back(x);
        }
      
        return ans;
        // Code here
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends