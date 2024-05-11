//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    sort(S.begin(),S.end());
		    do{
		        ans.push_back(S);
		    }
		    while(next_permutation(S.begin(),S.end()));
		    	return ans;
		}
	
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends