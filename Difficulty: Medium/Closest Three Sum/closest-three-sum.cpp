//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int close = arr[0] + arr[1] + arr[2];
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < arr.size() - 2 ; i++){
            int j = i + 1, k = arr.size() - 1;
            while(j < k){
                int sum3 = arr[i] + arr[j] + arr[k];
                if(abs(close - target) > abs(sum3 - target))
                    close = sum3;
                if(abs(target - sum3) == abs(target - close))
                    close = max(sum3, close);
                if(sum3 > target)
                    k--;
                else if(sum3 < target)
                    j++;
                else
                    return sum3;
            }
        }
        return close;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends