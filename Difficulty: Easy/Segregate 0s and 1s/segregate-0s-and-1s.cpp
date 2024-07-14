//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int cntone=0;
        int cntzero=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                cntzero++;
            }
            else if(arr[i]==1){
                cntone++;
            }
        }
        int i=0;
        while(cntzero>0){
            arr[i]=0;
            i++;
            cntzero--;
        }
        while(cntone>0){
             arr[i]=1;
             i++;
            cntone--;
        }
        
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
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends