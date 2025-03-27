//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
   int findPlatform(vector<int>& arive, vector<int>& dep) {
        // Your code here
        int n = arive.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({arive[i],-1});
            arr.push_back({dep[i],1});
        }
        sort(arr.begin(),arr.end());
        int ans = 0, cnt = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][1] == -1) cnt++;
            else cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends