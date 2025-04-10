//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        
        int V = houses.size();
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int x1 = houses[i][0];
                int y1 = houses[i][1];
                
                int x2 = houses[j][0];
                int y2 = houses[j][1];
                
                int d = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> inMST(V,false);
        int sum = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int u = p.second;
            
            if(inMST[u] == true){
                continue;
            }
            inMST[u] = true;
            sum += wt;
            
            for(auto& node: adj[u]){
                int nbr = node.first;
                int w = node.second;
                
                if(inMST[nbr] == false){
                    pq.push({w,nbr});
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends