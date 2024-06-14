//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long ans=INT_MIN;
        long sum=0;
        //first K window sum
        for(int i=0;i<K;i++){
            sum+=Arr[i];
        }
        ans =max(ans,sum);
        
        //next K to N element
        for(int i=K;i<N;i++){
            sum+=Arr[i]-Arr[i-K];
            ans = max(ans,sum);
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends