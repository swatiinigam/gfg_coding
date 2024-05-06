//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution {
private:
bool ispo(int mid , int A[], int n, int m){
    int cnt = 0;
    int sumAl = 0;
    for(int i = 0; i< n ; i++){
        if(sumAl + A[i] > mid){
            cnt++;
            sumAl = A[i];
            if(A[i] > mid) return false;
        }
        else sumAl += A[i];
    }
    if(cnt < m) return true;
    return false;
}

    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N< M) return -1;
        int low = A[0];
        int high = A[0];
        for(int i =1; i< N; i++){
            high += A[i];
            low = min(low,A[i]);
        }
        while(low <= high){
            int mid = (low+high)>>1;
            if(ispo(mid,A,N,M)){
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends