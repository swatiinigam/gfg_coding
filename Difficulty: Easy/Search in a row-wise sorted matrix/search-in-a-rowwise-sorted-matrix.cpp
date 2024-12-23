//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        bool res;
        for(int i=0;i<n;i++){
            if(x>mat[i][m-1]) continue;
            res=binarySearch(mat[i],0,m-1,x);
            if(res) return true;
        }
        return res;
    }
    
    bool binarySearch(vector<int> arr, int low, int high, int x){
        while(low<=high){
            int mid=(low+high)/2;
            if(x==arr[mid]) return true;
            if(x<arr[mid]) high=mid-1;
            if(x>arr[mid]) low=mid+1;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends