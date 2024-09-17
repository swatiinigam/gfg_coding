//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Step 1: Initialize distance array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // Step 2: Relax edges up to K + 1 times
        for (int i = 0; i <= K; ++i) {
            vector<int> temp(dist);  // Copy current distances
            
            // Relax all edges
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];
                
                if (dist[u] != INT_MAX && dist[u] + cost < temp[v]) {
                    temp[v] = dist[u] + cost;
                }
            }
            
            dist = temp;  // Update distances
        }
        
        // Step 3: Return the result
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends