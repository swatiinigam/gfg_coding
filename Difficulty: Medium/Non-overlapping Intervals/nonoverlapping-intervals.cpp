//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        int count =0;
        
        int spoint = intervals[0][0];
        int epoint = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(spoint == intervals[i][0])
            {
                count++;
                continue;
            }
            else if(epoint > intervals[i][0])
            {
                if(epoint < intervals[i][1])
                {
                    count++;
                }
                else
                {
                    count++;
                    spoint =intervals[i][0];
                    epoint =intervals[i][1];
                }
            }
            else if(epoint <= intervals[i][0])
            {
                spoint = intervals[i][0];
                epoint = intervals[i][1];
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends