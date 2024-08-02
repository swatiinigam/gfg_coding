//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
        vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
        {
            // code here
            //store the net ammount to paid (or taken if -ve)
           vector<int> net(n, 0);
        
           for(int i = 0; i < n; i++)
           {
              for(int j = 0; j < n; j++)
              {
                 net[i] -= transaction[i][j];
                 net[j] += transaction[i][j];
              }
           }
           // for(int i = 0; i < n; i++)
           // {
           //    cout<<net[i]<<" ";
           // }
           vector<vector<int> > ans(n,vector<int> (n, 0));
           while(1)
           {
              bool allZero = true;
              int mini = INT_MAX;
              int maxi = INT_MIN;
              int mindex = 0;
              int maxdex = 0;
              for(int i = 0; i < n; i++)
              {
                 if(net[i] < mini ) 
                 {
                    mini = net[i];
                    mindex = i;
                 }
                 if(net[i] > maxi ) 
                 {
                    maxi = net[i];
                    maxdex = i;
                 }
              if(net[i] != 0) allZero = false;
              }
        
              if(allZero || maxi == 0 ) return ans;
              if(net[maxdex] >= abs(mini))
              {
                 net[mindex] = 0;
                 net[maxdex] -= abs(mini); 
                 ans[mindex][maxdex] = min(abs(mini),maxi );
        
              }
              else if(net[maxdex] < abs(mini))
              {
                 net[mindex] += maxi;
                 net[maxdex] = 0;
        
                 ans[mindex][maxdex] = min(abs(mini),maxi );
              }
           }
           // transaction = ans;
           return ans;
        }
};


//{ Driver Code Starts.

vector<int> balance(vector<vector<int>>& v, int n) {
    vector<int> bal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bal[i] -= v[i][j];
            bal[j] += v[i][j];
        }
    }
    return bal;
}

bool isValid(vector<vector<int>>& g, vector<vector<int>>& r, int n) {
    return balance(g, n) == balance(r, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution obj;
        vector<vector<int>> r = obj.minCashFlow(g, n);
        if (isValid(g, r, n) == false) {
            cout << "-1\n";
            continue;
        }
        int flow = 0;
        for (auto j : r) {
            for (auto i : j) {
                if (i > 0)
                    flow++;
            }
        }
        cout << flow << "\n";
    }
    return 0;
}
// } Driver Code Ends