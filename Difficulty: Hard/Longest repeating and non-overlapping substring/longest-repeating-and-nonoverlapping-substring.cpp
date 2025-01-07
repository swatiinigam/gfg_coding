//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestSubstring(string&s) {
        int n=s.size();
        int start=0;
        int end;
        if(n%2==0){
            end = (n/2);
        }else{
            end = (n/2)+1;
        }
        int mid = (start+end)/2;
        string ans="";
        while(start<=end){
            string res = "";
            for(int i=0;i<n;i++){
                string pattern = s.substr(i,mid+1);
                if(pattern.size()<mid+1){
                    break;
                }
                string temp = s.substr(0,i);
                string temp2 = s.substr(i+mid+1,n-(i+mid+1));
                if(temp.find(pattern)!=string::npos || temp2.find(pattern)!=string::npos ){
                    res = pattern;
                    break;
                }
            }
            if(res==""){
                end = mid-1;
            }else{
                ans = res;
                start = mid+1;
            }
            mid = (start+end)/2;
        }
        if(ans==""){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends