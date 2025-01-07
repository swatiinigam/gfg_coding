//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int arr[],int n,int k,int mid)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]+sum<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                count++;
                if(count>k || arr[i]>mid)
                {
                    return false;
                }
                sum=arr[i];
            }
        }
        return true;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            mini=min(mini,arr[i]);
        }
        int end=sum;
        int start=mini;
        int ans=0;
        int mid=start+(end-start)/2;
        
        while(start<=end)
        {
            if(isPossible(arr,N,K,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends