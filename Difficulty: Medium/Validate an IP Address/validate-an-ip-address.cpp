//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int cnt = 0;
        if(str[str.length()-1] == '.') return false;
        for(int i=0; i<str.length(); i++)
        {
            string temp = "";
            while(i<str.length() && str[i]!='.')
            {
                temp += str[i];
                i++;
            }
            if(temp.length() == 0) return false;
            if(temp.length()>1 && temp[0] == '0') return false;
            if(stoi(temp) > 255) return false;
            cnt++;
        }
        return (cnt == 4);
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends