//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: input array
    // Function to find the maximum index difference.
   int maxIndexDiff(vector<int>& arr) {
      int n = arr.size();
      vector<int>leftarray;
      vector<int>rightarray(n);
      int mini = INT_MAX;
      for(int i=0; i<n; i++){
          mini = min(mini, arr[i]);
          leftarray.push_back(mini);
      }
     int maxi = INT_MIN;
      for(int i=n-1; i>=0; i--){
          maxi = max(maxi, arr[i]);
          rightarray[i] = maxi;
      }
      int i=0;
      int j = 0;
      int ans = 0;
      while(i<n && j<n){
          if(leftarray[i]<=rightarray[j]){
              ans = max(ans, j-i);
              j++;
          }
          else{
              i++;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}
// } Driver Code Ends