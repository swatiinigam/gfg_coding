//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
                unordered_map<string, vector<string>> anagram_map;

        // Iterate through each string in the list
        for (const string& str : arr) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());

            // Add the original string to the map with the sorted string as the key
            anagram_map[sorted_str].push_back(str);
        }

        // Collect the grouped anagrams
        vector<vector<string>> result;
        for (const auto& entry : anagram_map) {
            result.push_back(entry.second);
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

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends