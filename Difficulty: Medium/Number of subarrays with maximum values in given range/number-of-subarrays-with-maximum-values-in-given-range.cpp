//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include <vector>
#include <queue>

class Solution {
public:
    long countSubarrays(int arr[], int n, int l, int r)
    {
        // Complete the function
        long long count =0, i=0,j=0;
        int window=0;
        while(j<n){
            if(arr[j]>=l and arr[j]<=r){
                window=j-i+1;
            }
            else if(arr[j]>r){
                window=0;
                i=j+1;
            }
            count+=window;
            j++;
        }
        return count;
        
    }
};



//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends