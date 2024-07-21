//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MIN, zeros=0, count=0;
        long long int prod = 1;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeros++;
                continue;
            }
            if(arr[i]<0){
                count++;
                mini = max(mini,arr[i]);
            }
            prod *= arr[i];
            prod%=mod;
        }
        if(count==1 && zeros+count==n)
            return 0;
        if(count%2)
            prod/=mini;
        return prod;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends