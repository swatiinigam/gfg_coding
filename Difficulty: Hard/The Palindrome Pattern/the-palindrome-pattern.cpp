//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool isPalindromeR(int row,int n, vector<vector<int>> &arr){
        int s=0,l=n-1;
        while(s<l){
            if(arr[row][s]!=arr[row][l]) return false;
            s++;
            l--;
        }
        return true;
    }
    
    bool isPalindromeC(int col,int n, vector<vector<int>> &arr){
        int s=0,l=n-1;
        while(s<l){
            if(arr[s][col]!=arr[l][col]) return false;
            s++;
            l--;
        }
        return true;
    }
    
    string pattern(vector<vector<int>> &arr) {
        int n=arr.size();
        for(int row=0;row<n;row++){
            bool p=isPalindromeR(row,n,arr);
            if(p==true) return to_string(row)+" R";
        }
        for(int col=0;col<n;col++){
            bool p=isPalindromeC(col,n,arr);
            if(p==true) return to_string(col)+" C";
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends