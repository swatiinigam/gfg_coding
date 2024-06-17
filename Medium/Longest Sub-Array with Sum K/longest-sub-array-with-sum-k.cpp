//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int maxLength=0;
        int sum=0;
        map<int,int> mpp;
        
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum == K){
                maxLength=i+1;
            }
            if(mpp.find(sum-K) != mpp.end()){
                maxLength= max (maxLength,i-mpp[sum-K]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum]=i;
            }
        }
        
        return maxLength;
        
    }

};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends