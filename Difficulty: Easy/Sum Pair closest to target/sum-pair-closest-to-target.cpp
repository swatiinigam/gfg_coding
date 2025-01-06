//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
   vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); 
        int gi = -1, gj = -1; 
        int gc = INT_MAX; 
        int absChecker = INT_MAX; 
        int n = arr.size(); 
        int i = 0 ;
        int j = arr.size()-1; 
        
        if(n < 2){
            return {}; 
        }
        
        while(i<j){
            int sum = arr[i]+arr[j]; 
            if(sum < target){
                int hms = target-sum; 
                if(hms < gc){
                    gc = hms; 
                    gi = i;
                    gj = j; 
                }
                else if(hms == gc){
                    int num = abs(arr[i]-arr[j]); 
                    if(num > absChecker){
                        gi = i; gj = j; 
                    }
                }
                i++; 
            }
            else if(sum == target){
                return {arr[i],arr[j]}; 
            }
            else{
                int hmg = sum - target; 
                if(hmg<gc){
                    gc = hmg; 
                    gi = i; 
                    gj = j; 
                }
                else if(hmg == gc){
                    int num = abs(arr[i]-arr[j]); 
                    if(num > absChecker){
                        gi = i; gj = j; 
                    }
                }
                j--; 
            }
        }
        
        return {arr[gi], arr[gj]}; 
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends