//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
   int func(int ind,int buy,vector<int>&prices,vector<vector<vector<int>>> &dp,int n,int l){
    if(l==0){
        return 0;
    }
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy][l]!=-1) return dp[ind][buy][l];
        if(buy){
            return dp[ind][buy][l]= max(-prices[ind]+func(ind+1,0,prices,dp,n,l),
             func(ind+1,1,prices,dp,n,l));
        }
        else{
            return dp[ind][buy][l] = max(prices[ind]+func(ind+1,1,prices,dp,n,l-1),func(ind+1,0,prices,dp,n,l));
        }
    }
    public:
int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    int l=2;
     return func(0,1,price,dp,n,l);
    
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends