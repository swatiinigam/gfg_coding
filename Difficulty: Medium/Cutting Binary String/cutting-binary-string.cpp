class Solution {
  public:
  vector<vector<int>>dp;
bool isPowerOfFive(int n) {
    if (n < 1) return false;
    while (n % 5 == 0) {
        n /= 5;
    }
    return n == 1;
}

    
int bintodec(const string &s) {
    int result = 0;
    for (char c : s) {
        result = result * 2 + (c - '0');
    }
    return result;
}

    
    int recur(string &s, int i, int j) {
        // Imaginary string
        if(i>j) {
            return -1;
        }
        // Single character string
        if(i==j) {
            if(s.at(i)=='1') {
                return 1;
            }
            return -1;
        }
        
        // Remove leading zero strings
        if(s.at(i)=='0') {
            return -1;
        }
        
        if(dp[i][j]!=-2) {
            return dp[i][j];
        }
        
        string current = s.substr(i,j-i+1);
        
        // Check if current string power of 5
        int x = bintodec(current);
        if(isPowerOfFive(x)) {
            return 1;
        }
        
        //Recursively check all partitions of the string
        int mini = INT_MAX;
        for(int k=i;k<j;k++) {
            int init = recur(s,i,k);
            int fin = recur(s,k+1,j);

            if(init != -1 && fin!=-1) {
                mini=min(mini,fin+init);
            }
            
        }
        return dp[i][j] =  (mini == INT_MAX) ? -1 : mini;

    }
  
    int cuts(string s) {
        dp = vector<vector<int>>(s.length()+1,vector<int>(s.length()+1,-2));
        return recur(s, 0, s.length() - 1);
    }
};