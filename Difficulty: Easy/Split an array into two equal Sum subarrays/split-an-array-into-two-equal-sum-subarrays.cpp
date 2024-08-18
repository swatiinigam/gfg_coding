//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int i,tsum=0;
        int n=arr.size();
        for(i=0;i<n;i++){
            tsum+=arr[i];
        }
        if(tsum%2!=0){
            return false;
        }
        int target=tsum/2;
        int cursum=0;
        for(i=0;i<n;i++){
            cursum+=arr[i];
            if(cursum==target){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends