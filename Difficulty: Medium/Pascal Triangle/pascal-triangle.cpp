//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> prev(1 , 1) ; 
        for(int i = 2 ; i <= n ; i++){
            vector<int> curr(i , 1) ; 
            for(int j = 1 ; j < i-1 ; j++){
                curr[j] = prev[j] + prev[j-1] ; 
            }
            prev = curr ; 
        }
        return prev ; 
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends