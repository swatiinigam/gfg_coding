//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans;
        vector<int>flag(n,1);
        for(int i=0;i<s.size();i++){
            char c = s[i];
            set<string>st;
            for(int j=0;j<n;j++){
                if(contact[j].size()>i && contact[j][i]==c && flag[j] ){
                    st.insert(contact[j]);
                }
                else{
                    flag[j] = 0;
                }
            }
            if(st.empty()){
                ans.push_back({"0"});
            }
            else{
               vector<string>temp(st.begin(),st.end());
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends