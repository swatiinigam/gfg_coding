//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        vector<int> result;
        deque<int> dq;
        
        // Process the first window separately
        for (int i = 0; i < k; ++i) {
            // Remove elements from the back of deque which are smaller than current element
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        // Process remaining windows
        for (int i = k; i < n; ++i) {
            // The front of the deque is the maximum element for the current window
            result.push_back(arr[dq.front()]);
            
            // Remove elements from the front of deque which are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back of deque which are smaller than current element
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            
            // Add current element's index to deque
            dq.push_back(i);
        }
        
        // Add the maximum of the last window
        result.push_back(arr[dq.front()]);
        
        return result;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends