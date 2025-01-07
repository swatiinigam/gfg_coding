//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
vector<int> generateNextPalindrome(int num[], int n) {
    // code here
    bool change = 1;    //because current number has to change
    for(int i=0; i<n/2; i++){
        if(num[i] > num[n-i-1]){
            change = 0; //because the current number will become larger
        }
        else if(num[i] < num[n-i-1]){
            change = 1; //current number become smaller than previous
        }
        num[n-i-1] = num[i];
    }
    
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[i] = num[i];
    }
    
    //code to make the number larger than previous
    int index = n/2;
    bool carry = change;
    while(carry && index < n){
        if(ans[index] == 9){
            ans[index] = 0;
            ans[n-index-1] = ans[index];
        }
        else{
            ++ans[index];
            ans[n-index-1] = ans[index];
            carry = 0;
        }
        ++index;
    }
    
    if(carry){
        ans[0] = 1;
        ans.push_back(1);
    }
    return ans;
}
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends