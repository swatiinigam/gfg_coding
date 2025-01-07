//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        long long maxi = (long long)*max_element(types.begin(),types.end());
        
        vector<vector<long long>> pos(maxi+1,vector<long long>(2,-1));
        set<long long> uni;
        
        for(long long i = 0;i<types.size();i++){
            if(uni.count(types[i])==0){
                pos[types[i]][0] = (long long)locations[i];
                pos[types[i]][1] = (long long)locations[i];
                uni.insert(types[i]);
            }
            else{
                if(pos[types[i]][0]>locations[i]){
                    pos[types[i]][0] = (long long)locations[i];
                }
                else if(pos[types[i]][1]<locations[i]){
                    pos[types[i]][1] = (long long)locations[i];
                }
            }
        }
        
        
        vector<vector<long long>> dp(uni.size()+1,vector<long long>(4,0LL));

        long long i = 1LL;
        for(auto it:uni){
            long long ty = it;
            
            long long left = pos[ty][0];
            long long right = pos[ty][1];
            //left to right
            long long nc = min(dp[i-1][0]+abs(dp[i-1][1]-left)+(right-left),dp[i-1][2]+abs(dp[i-1][3]-left) + (right-left));
            dp[i][0] = nc;
            dp[i][1] = right;
            
            //right to left
            nc = min(dp[i-1][0]+abs(dp[i-1][1]-right)+(right-left),dp[i-1][2]+abs(dp[i-1][3]-right) + (right-left));
            dp[i][2] = nc;
            dp[i][3] = left;
            i++;
        }
        
        return min(dp[i-1][0] + abs(dp[i-1][1]), dp[i-1][2] + abs(dp[i-1][3]));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends