//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xor1=0, xor2=0;
        for(int i=0; i<n; i++)
        xor1 = xor1^arr[i];
        
        n = n+1;
        if(n%4==0)
         return xor1^n;
        else if(n%4==1)
         return xor1^1;
        else if(n%4==2)
         return xor1^(n+1);
        else
            return  
            xor1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends