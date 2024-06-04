//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
private:
    void findComb(int ind, int target, vector<int> &A, vector<vector<int>> &ans, vector<int> &ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    
    for (int i = ind; i < A.size(); i++) {
        if (A[i] <= target && (i == ind || A[i] != A[i - 1])) {
            ds.push_back(A[i]);
            findComb(i, target - A[i], A, ans, ds);
            ds.pop_back();
        }
    }
}
 public:
   vector<vector<int>> combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(A.begin(), A.end()); // Sort the input array to ensure non-descending order
    findComb(0, B, A, ans, ds);
    return ans;
}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends