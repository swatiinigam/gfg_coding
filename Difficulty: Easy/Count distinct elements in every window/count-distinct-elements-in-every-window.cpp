//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int>ans;
        map<int,int>m;
        int n=arr.size();
        for(int i=0;i<k;i++){
            m[arr[i]]++;
        }
        ans.push_back(m.size());
        int j=0;
        for(int i=k;i<n;i++){
            m[arr[j]]--;
            if(m[arr[j]]==0){
                m.erase(arr[j]);
            }
            j++;
            m[arr[i]]++;
            ans.push_back(m.size());
            
        }
        return ans;
    }


};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends