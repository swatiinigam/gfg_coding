//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int find_index(const vector<int>& arr, int left, int right, int limit) {
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < limit) {
                result = mid; 
                left = mid + 1;
            } else {
                right = mid - 1; 
            }
        }
        return result;
    }
    int countTriangles(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int side1 = arr[i];
                int side2 = arr[j];
                int limit = side1 + side2;
                int k = find_index(arr, j + 1, arr.size() - 1, limit);
                if(k!= -1)ans+=(k-j);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
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
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends