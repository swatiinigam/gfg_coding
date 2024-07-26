//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <unordered_set>
#include <string>
#include <cctype> // for isalpha and tolower

class Solution {
public:
   bool kPangram(string str, int k) {
       map<char,int>m;
       for(auto i:str) {
           if(i>='a' and i<='z') m[i]++;
       }
       int count=0;
       for(auto i:m){
           if(i.second>1) count+=(i.second-1);
       }
       if(count<k) k=count;
       for(char i='a';i<='z';i++){
           if(!m[i]){
               if(k==0) return false;
               else k--;
           }
       }
       return true;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends