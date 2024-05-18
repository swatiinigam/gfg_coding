//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
    if (k <= 0 || k > q.size()) {
        return q;
    }

    stack<int> st;

    // Step 1: Dequeue and push the first K elements onto the stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Pop the elements from the stack and enqueue them back into the queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move the first (q.size() - k) elements to the rear of the queue
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends