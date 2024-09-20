//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    // Returns count of buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int cnt = 0;
        int n = height.size();
        int maxHeight = 0; // To keep track of the tallest building seen so far
        
        for (int i = 0; i < n; i++) {
            // A building can see sunlight if it is taller than maxHeight seen so far
            if (height[i] > maxHeight) {
                cnt++;       // Count this building
                maxHeight = height[i]; // Update maxHeight
            }
        }
        
        return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends