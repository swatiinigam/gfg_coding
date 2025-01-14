//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        
        vector<int>vl(arr.size());
        vector<int>vr(arr.size());
        
        vl[0] = arr[0];
        vr[arr.size()-1] = arr[arr.size()-1];
        
        for(int i=1;i<arr.size();i++){
            vl[i] = vl[i-1] + arr[i];
        }
        for(int i=arr.size()-2;i>=0;i--){
            vr[i] = vr[i+1] + arr[i];
        }
        for(int i=1;i<arr.size()-1;i++){
            if(vl[i-1]==vr[i+1]){
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends