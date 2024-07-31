//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> arr) {
        int N = arr.size();
        sort(arr.begin(),arr.end());
        string s1 = arr[0];
        string s2 = arr[N-1];
        string ans;
        int size1 = s1.size();
        int size2 = s2.size();
        int i = 0, j = 0;
        while(i<size1 && j<size2){
            if(s1[i]==s2[j]){
                ans.push_back(s1[i]);
                
            }
            else{
                break;
            }
            i++;
            j++;
        }
        if(ans.size()==0){
            return "-1";
        }
        else{
            return ans;
        }
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends