//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string res;
        int carry=0;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int n1 = s1.size();
        int n2 = s2.size();
        int i=0;
        while(i<n1 && i<n2){
            int add = carry;
            add = add + (s1[i]-'0') + (s2[i]-'0');
            carry=0;
            if(add==0) res+='0';
            else if(add==1) res+='1';
            else if(add==2){
                res+='0';
                carry=1;
            }
            else{
                res+='1';
                carry=1;
            }
            i++;
        }
        
        while(i<n1){
            int add = carry;
            add = add + (s1[i]-'0');
            carry=0;
            if(add==0) res+='0';
            else if(add==1) res+='1';
            else if(add==2){
                res+='0';
                carry=1;
            }
            i++;
        }
        while(i<n2){
            int add = carry;
            add = add + (s2[i]-'0');
            carry=0;
            if(add==0) res+='0';
            else if(add==1) res+='1';
            else if(add==2){
                res+='0';
                carry=1;
            }
            i++;
        }
        
        if(carry==1) res+='1';
        
        reverse(res.begin(), res.end());
        
        string final_ans="";
        i=0;
        int n=res.size();
        
        while(i<n && res[i]=='0') i++;
        
        while(i<n){
            final_ans+=res[i];
            i++;
        }
        
        return final_ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends