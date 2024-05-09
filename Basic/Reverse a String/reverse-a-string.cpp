//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution {
private:
    void reverseWord2(string &str, int i, int j) {
        if (i >= j) {
            return;
        }
        swap(str[i], str[j]);
        reverseWord2(str, i + 1, j - 1);
    }
public:
    string reverseWord(string str) {
        int n = str.size();
        reverseWord2(str, 0, n - 1);
        return str;
    }
};




//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends