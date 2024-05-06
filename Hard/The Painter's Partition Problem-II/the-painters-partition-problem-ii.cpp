//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#include <vector>
#include <climits>

class Solution
{
     bool ispossiblesolution(int arr[],int n,int K,long long mid){
        long long timesum =0;
        int c=1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            if(timesum+arr[i]>mid){
                c++;
                timesum=arr[i];
            
                if(c>K){
                    return false;
                }    
            }
            else{
                timesum+=arr[i];
            }
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long start=0;
        long long end=0;
     for(int i=0;i<n;i++){
        end +=arr[i];
     }
        long long ans=-1;
        while(start<=end){
            long long mid=start +(end-start)/2;
            if(ispossiblesolution(arr,n,k,mid)){
                ans=mid;
                end=mid-1;
                
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends