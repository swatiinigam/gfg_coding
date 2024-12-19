//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        map<int,bool>mp;
        int n=arr.size() - 1;
        int maxi=arr[n];
        for(int i=1;i <= maxi;i++){
            mp[i]=false;
        }
        for(int i=0;i<=n;i++){
            mp[arr[i]]=true;
        }
        int cnt=0;
        vector<int>ans;
        for(auto i:mp){
            if(i.second == false){
                ans.push_back(i.first);
                cnt++;
            }
        }
        if(cnt >= k){
            int ansi=ans[k - 1];
            return ansi;
        }
        int val=k - cnt;
        int anss=maxi + val;
        return anss;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends