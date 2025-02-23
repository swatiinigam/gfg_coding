//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int>ans;
        //for descending order array
        bool isDes = true;
        for(int i=0;i<arr.size();i++){
            if(arr[i] < arr[i+1]){
                isDes = false;
                break;
            }
        }
        if(isDes) return vector<int>(arr.size(),-1);
        
        //normal case
        for(int i=0;i<arr.size();i++){
            int gt = -1,j=i+1;
            while(j < arr.size()){
                if(arr[i] < arr[j]){
                    gt = arr[j];
                    break;
                }
                j++;
            }
                ans.emplace_back(gt);
                
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends