//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long max_sum(int a[], int n) {
        long long res = 0, totalSum = 0, maxi = 0;
        
        for(int i = 0; i < n; i++) {
            totalSum += a[i];
            res += (i * 1ll * a[i]);
        }
        
        maxi = max(maxi, res);
        for(int i = 0; i < n; i++) {
            res = res - (totalSum - a[i]) + (a[i] * 1ll * (n - 1));
            maxi = max(maxi, res);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends