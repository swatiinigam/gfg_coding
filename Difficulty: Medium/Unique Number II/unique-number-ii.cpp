//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int xorr=0;
        int n=arr.size();
        for(int i=0; i<n; i++){
            xorr^=arr[i];
        }
        int set=((xorr&(xorr-1))^xorr);
        int x1=0, x2=0;
        for(int i=0; i<n; i++){
            int num=arr[i];
            if (num & set)
                x1 ^= num;
            else
                x2 ^= num;
        }
        if(x1>x2) return {x2, x1};
        else return {x1, x2};
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends