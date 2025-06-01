class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_map<int,int>mp;
        int n=mat1.size();
        int m=mat2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat1[i][j]]++;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int target=x-mat2[i][j];
                if(mp.find(target)!=mp.end()){
                    count+=mp[target];
                }
            }
        }
        return count;
    }
};