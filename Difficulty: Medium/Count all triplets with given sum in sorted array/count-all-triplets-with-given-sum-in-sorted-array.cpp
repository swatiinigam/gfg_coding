//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int count = 0;
        
        unordered_map<int,int>mp;
        mp[arr[0]]++;
        
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int new_target=arr[i]+arr[j];
                
                int rem_sum=target-new_target;
                if(mp.find(rem_sum)!=mp.end()) 
                count+=mp[rem_sum];
            }
            
            mp[arr[i]]++;
        }
        
        return count;
    }
};



//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends