//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
	void dfs(int node, vector<int>& visited, vector<int>adj[],stack<int>& st) {
        visited[node] = 1;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
     void revdfs(int node, vector<int>& visited, vector<int>adj[], vector<int>& res) {
        visited[node] = 1;
        res.push_back(node);
        for(auto it: adj[node]) {
            if(!visited[it]) {
                revdfs(it,visited,adj,res);
            }
        }
        
    }
    public:
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
       vector<int>visited(V,0);
       stack<int>st;
       for(int i=0;i<V;i++) {
           if(!visited[i]) {
               dfs(i,visited,adj,st);
           }
       }
       
       vector<int>transpose[V];
       for(int i=0;i<V;i++) {
           visited[i] = 0;
           for(auto it: adj[i]) {
               transpose[it].push_back(i);
           }
       }
       
       vector<int>res;
       vector<vector<int>>ans;
       while(!st.empty()) {
           int top = st.top();
           st.pop();
           if(!visited[top]) {
               revdfs(top,visited,transpose,res);
                sort(res.begin(),res.end());
                ans.push_back(res);
           }
           res.clear();
       }
       sort(ans.begin(),ans.end());
       return ans;
    }


};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends