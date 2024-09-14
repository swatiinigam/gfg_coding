//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>p;
        vector<int>n;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                p.push_back(arr[i]);
            }
            else{
            n.push_back(arr[i]);
        }
        
        }
        int s=arr.size();
        int i=0;
        int j=0;
        int k=0;
        while(i<s){
            if( j<p.size()){
                arr[i]=p[j];
                i++;
                j++;
            }
         if( k<n.size()){
                arr[i]=n[k];
                i++;
                k++;
            }
            
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends