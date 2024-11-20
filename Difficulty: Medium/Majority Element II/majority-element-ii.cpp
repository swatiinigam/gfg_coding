//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        sort(arr.begin(), arr.end());
        
        int OccuranceCount = 1;
        int prev = arr[0];
        
        for(int i = 1; i < n; i++) {
            if(arr[i] == prev) {
                OccuranceCount++;
            } else {
                if(OccuranceCount > n/3) {
                    result.push_back(prev);
                }
                OccuranceCount = 1;
                prev = arr[i];
            }
        }
        
        // Check for the last element
        if(OccuranceCount > n/3) {
            result.push_back(prev);
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends