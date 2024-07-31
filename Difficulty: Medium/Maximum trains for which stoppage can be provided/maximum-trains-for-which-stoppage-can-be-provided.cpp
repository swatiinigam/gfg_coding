//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

#include <vector>
#include <algorithm>
using namespace std;

struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[3] <= b[3];
        }
        return a[1] <= b[1];
    }
};

class Solution {
  public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        for(int i=0; i<m; i++)
            trains[i].push_back(i);
            
        sort(trains.begin(), trains.end(), comp());
        vector<int> platform(n+1, -1);

        int ans = 0;
        
        for(int i=0; i<m; i++) {
            if(platform[trains[i][2]] <= trains[i][0]) {
                ans++;
                platform[trains[i][2]] = trains[i][1];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> trains(m, vector<int>(3));
        Matrix::input(trains,m,3);
        
        Solution obj;
        int res = obj.maxStop(n, m, trains);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends