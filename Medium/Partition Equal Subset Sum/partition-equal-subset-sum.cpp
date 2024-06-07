//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:
    int solve(int N,int *arr,int target,int i,vector<vector<int>>&dp){
        if(i==N){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        
        int incl =solve(N,arr,target-arr[i],i+1,dp);
        int exc =solve(N,arr,target,i+1,dp);
        
        dp[i][target] = incl||exc;
        return dp[i][target];
        
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        int target =sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return solve(N,arr,target,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends