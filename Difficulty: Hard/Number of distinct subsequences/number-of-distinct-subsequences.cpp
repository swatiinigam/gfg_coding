//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int mod = 1000000007;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    
	    vector<int> arr(26,-1);
	    long ans = 0;
	    long diff = 0;
	    
	    for(int i =0;i<n;i++){
	        int x = s[i] - 'a';
	        if(i==0){
	            ans =1;
	            arr[x]=1;
	            continue;
	        }
	        
	        diff =ans+1;
	        
	        if(arr[x]==-1){
	            ans = (ans+diff)%mod;
	        }else{
	            ans = (ans+diff-arr[x])%mod;
	        }
	        arr[x]=diff;
	    }
	    
	    ans+=1;
	    
	    return (int)(ans<0?ans+mod:ans);
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends