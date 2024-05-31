//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Priority queue to store (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Distance vector to store the shortest distance from source to each node
        vector<int> dist(V, INT_MAX);
        
        // Initialize the source node's distance to 0 and push it to the priority queue
        dist[S] = 0;
        pq.push({0, S});
        
        while (!pq.empty())
        {
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            // Traverse through all the adjacent nodes of currNode
            for (auto &neighbor : adj[currNode])
            {
                int adjNode = neighbor[0];
                int weight = neighbor[1];
                
                // Relaxation step
                if (currDist + weight < dist[adjNode])
                {
                    dist[adjNode] = currDist + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        // Replace INT_MAX with -1 to signify that a node is not reachable from the source
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends