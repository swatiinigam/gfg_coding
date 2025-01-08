//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    int countBits(int N, long long int A[])
    {
        long long int ans=0;
        for(int i=0;i<=31;i++){
            long long int set=0;
            long long int unset=0;
            for(int j=0;j<N;j++){
                if((A[j]>>i)&1)set++;
                else unset++;
            }
            ans=(ans+set*unset*2)%mod;
        }
        return (int)ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends