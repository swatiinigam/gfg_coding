//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
         int a=0, b=0, c=0, d=0, i=0;

// string is of the form : "a/b, c/d"
        
        while(str[i] != '/')
        a = a*10 + (str[i++] - '0');
        
        i += 1;      //skip "/"
        
        while(str[i] != ',')
        b = b*10 + (str[i++] - '0');
        
        i += 2;     // skip ", "
        
        while(str[i] != '/')
        c = c*10 + (str[i++] - '0');
        
        i += 1;     //skip "/"
        
        while(i < str.size())
        d = d*10 + (str[i++] - '0');
        
        if(a*d > b*c)
        return (to_string(a) + "/" + to_string(b));
        else if(a*d < b*c)
        return (to_string(c) + "/" + to_string(d));
        else
        return "equal";
         
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends