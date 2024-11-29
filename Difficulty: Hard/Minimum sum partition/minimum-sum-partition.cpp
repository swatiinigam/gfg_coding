//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minDifference(vector<int>& nums) {
        int sum = 0;
        for(auto &e : nums){
            sum += e;
        }
        int target = sum;
        int n = nums.size();
        vector<bool> prev (target + 1, false);
        prev[0] = true;
        prev[nums[0]] = true;
        for(int i = 1; i < n; i++){
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for(int j = 1; j <= target; j++){
                curr[j] = prev[j];
                if(nums[i] <= j && prev[j - nums[i]]){
                    curr[j] = true;
                }
            }
            prev = curr;
        }
        target = sum/2;
        while(!prev[target]){
            target--;
        }
        return sum - 2*target;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends