//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
         stack<int> st;
        long long maxArea = 0;
        long long area = 0;
        int i = 0;

        while (i < n) {
            if (st.empty() || arr[st.top()] <= arr[i]) {
                st.push(i);
                i++;
            } else {
                int top = st.top();
                st.pop();
                area = arr[top] * (st.empty() ? i : (i - st.top() - 1));
                maxArea = max(maxArea, area);
            }
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            area = arr[top] * (st.empty() ? i : (i - st.top() - 1));
            maxArea = max(maxArea, area);
        }

        return maxArea;

}


    
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends