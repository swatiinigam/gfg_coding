//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long seriesSum(int n) {
        // code here
        long sum=0;
        for(int i =1; i <=n;i++) {
            sum = sum + i;
            
        }
        return sum;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        long long res = obj.seriesSum(n);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends