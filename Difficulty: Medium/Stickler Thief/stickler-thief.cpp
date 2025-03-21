//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
   int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int prev1=arr[0], prev2=0, curr=0;
        for(int i=2; i<=n; i++){
            curr=max(prev1, arr[i-1]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends