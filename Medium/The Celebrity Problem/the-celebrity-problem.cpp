//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // push all people into stack
        stack<int> st;
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // pop top two people and check till only one person is left in the stack
        while(st.size() > 1) {
            int person1 = st.top();
            st.pop();
            int person2 = st.top();
            st.pop();
            
            // if person1 knows person2, then person1 is not the celebrity
            // so discard it and push person2 back into stack
            // if person1 does not know person2, then person1 may be celebrity,
            // push it back into the stack
            if(M[person1][person2] == 1) st.push(person2);
            else st.push(person1);
        }
        
        // the only person remaining in stack is potential candidate
        int ans = st.top();
        
        // check all people know celebrity except the celebrity himself
        for(int i = 0; i < n; i++) {
            if(M[i][ans] == 0 && i != ans) return -1;
        }
        // check celebrity knows no one
        for(int j = 0; j < n; j++) {
            if(M[ans][j] == 1) return -1;
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends