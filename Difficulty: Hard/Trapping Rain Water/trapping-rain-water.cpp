//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int maxWater(vector<int> &arr) {
        int lmx=0,rmx=0,l=0,r=arr.size()-1,res=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(arr[l]>lmx) lmx=arr[l];
                else res+=lmx-arr[l];
                l++;
            }
            else{
                if(arr[r]>rmx) rmx=arr[r];
                else res+=rmx-arr[r];
                r--;
            }
        }
        return res;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends