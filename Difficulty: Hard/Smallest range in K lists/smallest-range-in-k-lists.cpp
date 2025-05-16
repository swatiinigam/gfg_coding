//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        vector<pair<int,int>>a;
        for(int i =0;i<arr.size();++i) {
            for(int num:arr[i]) {
                a.push_back({num,i});
            }
        }
        sort(a.begin(),a.end());
        int left=0;
        int cnt=0;
        vector<int>freq(arr.size(),0);
        int min_=INT_MAX;
        vector<int>res;
        for(int right =0;right<a.size();++right){
            if(freq[a[right].second]==0)
                cnt++;
            freq[a[right].second]++;
            while(cnt==arr.size()){
                if(a[right].first-a[left].first< min_){
                    min_=a[right].first-a[left].first;
                    res={a[left].first,a[right].first};
                }
                freq[a[left].second]--;
                if(freq[a[left].second]== 0) 
                    cnt--;
                left++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends