class Solution {
  public:
   int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dis(n+1,vector<int>(m+1,0));
        if(grid[0][0]==0)
            dis[1][1]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(i+j==2)
                    continue;
                if(grid[i-1][j-1])
                    dis[i][j]=0;
                else
                    dis[i][j]=dis[i-1][j]+dis[i][j-1];
            }
        }
        return dis[n][m];
    }
};