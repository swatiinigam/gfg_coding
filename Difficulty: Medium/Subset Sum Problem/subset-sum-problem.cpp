//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int m = arr.size();
        vector<int> prev(target + 1);
        prev[0] = 1;
        for (int tar = 1; tar <= target; tar++)
        {
            if (tar == arr[0])
            {
                prev[tar] = 1;
            }
            else
            {
                prev[tar] = 0;
            }
        }
        for (int row = 1; row < m; row++)
        {
            vector<int> temp(target + 1);
            temp[0] = 1;
            for (int column = 1; column <= target; column++)
            {
                bool notTake = prev[column];
                bool take = false;
                if (column >= arr[row])
                {
                    take = prev[column - arr[row]];
                }
                temp[column] = (take || notTake);
            }
            prev = temp;
        }
        return prev[target];
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends