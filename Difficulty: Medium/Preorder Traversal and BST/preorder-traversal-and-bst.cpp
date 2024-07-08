//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int canRepresentBST(int arr[], int N) {
        stack<int> s;
        int root = INT_MIN;

        for (int i = 0; i < N; i++) {
            // If we find a node which is on the right side, return false
            if (arr[i] < root) {
                return 0;
            }

            // Keep removing elements from stack while stack is not empty
            // and stack top is smaller than arr[i]
            while (!s.empty() && s.top() < arr[i]) {
                root = s.top();
                s.pop();
            }

            // At this point either stack is empty or s.top() >= arr[i]
            s.push(arr[i]);
        }

        return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends