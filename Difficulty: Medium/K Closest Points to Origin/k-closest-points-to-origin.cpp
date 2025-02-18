//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    

    vector<vector<int>>ans;
    

    priority_queue<pair<int,vector<int>>>pq;
    
    
    for(int i=0;i<points.size();i++){
        
        
        int a=points[i][0];
        
        int b=points[i][1];
        
        int first=a*a+b*b;
        
        
        vector<int>second={a,b};
        
        
        if(pq.size()<k){
        
        pq.push({first,{second}});
        
        
        }
        
        else{
            
            if(pq.top().first>first){
                
                
                pq.pop();
                
                    pq.push({first,{second}});
                    
                    
            }
        }
        
    }
    
    
    while(!pq.empty()){
        
        
        
        vector<int>arr=pq.top().second;
        ans.push_back({arr});
        
        
        pq.pop();
    }
    
    return ans;
    
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends