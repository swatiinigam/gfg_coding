//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to return a list containing the union of the two arrays.
    std::vector<int> findUnion(std::vector<int> &a, std::vector<int> &b) {
        std::unordered_set<int> s;
        std::vector<int> v;
        
        // Insert elements from both arrays into the set to remove duplicates
        for(int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }
        for(int i = 0; i < b.size(); i++) {
            s.insert(b[i]);
        }
        
        // Insert all elements from the set into the vector
        for(const auto &elem : s) {
            v.push_back(elem);
        }
        
        // Sort the vector to get elements in order
        std::sort(v.begin(), v.end());
        
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends