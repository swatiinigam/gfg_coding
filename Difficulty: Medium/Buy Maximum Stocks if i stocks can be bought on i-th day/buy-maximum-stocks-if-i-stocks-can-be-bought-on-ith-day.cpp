//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({price[i],i+1});
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<v.size();i++){
            while(v[i].second>0) {
                if(k-v[i].first>=0) { k-=v[i].first; cnt++;}
                else break;
                v[i].second--;
            }
            if(v[i].second!=0) break; 
        }
        return cnt;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends