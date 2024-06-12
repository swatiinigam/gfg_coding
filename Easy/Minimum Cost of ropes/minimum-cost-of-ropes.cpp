//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Create a priority queue (min-heap)
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Push all elements into the priority queue
        for(int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        long long res = 0;
        
        // While more than one element is in the queue
        while(pq.size() > 1) {
            // Extract the two smallest elements
            long long val1 = pq.top();
            pq.pop();
            long long val2 = pq.top();
            pq.pop();
            
            // Combine the two elements and add the result back to the queue
            long long ans = val1 + val2;
            res += ans;
            pq.push(ans);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends