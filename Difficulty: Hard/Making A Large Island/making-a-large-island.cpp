//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int dfs(vector<vector<int>>& grid,int row,int col,int val){
        int n = grid.size();
        int m = grid[0].size();
        if(row <0 or row>=n or col<0 or col>=m or grid[row][col]!=1)
            return 0;
        
        grid[row][col] = val;
        int sum = 1;
        sum += dfs(grid,row+1,col,val);
        sum += dfs(grid,row-1,col,val);
        sum += dfs(grid,row,col-1,val);
        sum += dfs(grid,row,col+1,val);
        
        return sum;
    }

    int largestIsland(vector<vector<int>>& grid) 
    {   
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 2;
        int ans = -1;
        unordered_map<int,int> mp;
        int val=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt = dfs(grid,i,j,val);
                    mp[val] = cnt;
                    val++;
                    ans = max(ans,cnt);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0){
                    int x =0;
                    unordered_set<int> s;
                    if(i-1>=0 and grid[i-1][j]!=0)
                        s.insert(grid[i-1][j]);   
                    if(i+1<n and grid[i+1][j]!=0)
                        s.insert(grid[i+1][j]);
                    if(j-1>=0 and grid[i][j-1]!=0)
                        s.insert(grid[i][j-1]);
                    if(j+1<m and grid[i][j+1]!=0)
                        s.insert(grid[i][j+1]); 
                        
                    for(auto &it : s){
                        x += mp[it];
                    }
                    ans = max(ans,x+1);
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends