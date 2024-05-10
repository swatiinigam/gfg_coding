//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void solve(vector<int>& arr, int n, int k, int start, int sum, vector<int>& ans, vector<vector<int>>& output) {
        if (sum == k) {
            output.push_back(ans);
            return;
        }
        
        if (sum > k) {
            return;
        }
        
        for (int i = start; i < n; i++) {
            // Avoid duplicates
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }
            
            ans.push_back(arr[i]);
            solve(arr, n, k, i + 1, sum + arr[i], ans, output);
            ans.pop_back();
        }
    }
    
public:
    vector<vector<int>> CombinationSum2(vector<int>& arr, int n, int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        vector<vector<int>> output;
        solve(arr, n, k, 0, 0, ans, output);
        return output;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends