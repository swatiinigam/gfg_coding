class Solution {
  public:
   int dp[101][101][101];
    
    int solve(string&s1, string&s2, string& s3, int i, int j, int k) {
        
        if(i >= s1.length() || j >= s2.length() || k >= s3.length()){
            return 0;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(s1[i] == s2[j] && s2[j] == s3[k]){
            return dp[i][j][k] = 1 + solve(s1,s2,s3,i+1,j+1,k+1);
        }
        return dp[i][j][k] = max({
            solve(s1,s2,s3,i+1,j,k),
            solve(s1,s2,s3,i,j+1,k),
            solve(s1,s2,s3,i,j,k+1),
            solve(s1,s2,s3,i+1,j+1,k),
            solve(s1,s2,s3,i+1,j,k+1),
            solve(s1,s2,s3,i,j+1,k+1)
        });
    }
    int lcsOf3(string& s1, string& s2, string& s3) {
        
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0,0);
    }
};