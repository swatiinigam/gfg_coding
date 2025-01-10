//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(vector<int> &ratings) {
        // code here
         int N=ratings.size();
        
        vector<int> ans(N,1);
        
        for(int i = 1; i < N; i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1]+1;
            }
        }
        
        
        for(int i = N-2; i > -1; i--){
            if(ratings[i] > ratings[i+1]){
                ans[i] = max(ans[i] , ans[i+1]+1);
            }
        }
        return accumulate(ans.begin(), ans.end() , 0);
        
    }
    
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr = inputLine();

        Solution obj;
        cout << obj.minCandy(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends