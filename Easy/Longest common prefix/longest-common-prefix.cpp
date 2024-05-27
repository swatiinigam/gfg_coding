//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <vector>
#include <string>

class Solution{
public:
    vector<int> longestCommonPrefix(string str1, string str2){
        // code here
        vector<int> ans;
        int start_index=0,end_index=0;
        for(int i=1;i<str1.length();i++){
            if(str2.find(str1.substr(0,i)) != string::npos){
              start_index=0;//update start index
              end_index=i-1;//update end index
            }
        }
        //push start and end index in the ans
        ans.push_back(start_index);
        ans.push_back(end_index);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string str1,str2;
        cin >> str1>> str2;
        Solution ob;
        vector<int> p;
        p = ob.longestCommonPrefix(str1,str2);
        if(p[0]==-1)
        cout<<"-1\n";
        
        else
        cout<<p[0]<<" "<<p[1]<<"\n";
    }
    return 0;
}

// } Driver Code Ends