//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool check(string s){
    for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1] || s[i]==s[i-1]){
                return false;
            }
        }  
        return true;
  }
    string removeUtil(string &s) {
        // code here
          
        if(check(s)==true){
            return s;
        }
        string s1="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=s[i+1] && s[i]!=s[i-1]){
                s1.push_back(s[i]);
            }
        }
        return removeUtil(s1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        s = ob.removeUtil(s);
        if (s.size() == 0)
            cout << "\"\"";
        else
            cout << s << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends