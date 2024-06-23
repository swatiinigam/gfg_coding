//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarray(int N, vector<int> A, long long L, long long R) {
        // Helper function to count subarrays with sum <= maxSum
        auto countSubarraysWithSumLessThanOrEqualTo = [](const vector<int>& A, int N, long long maxSum) {
            long long count = 0;
            long long currentSum = 0;
            int start = 0;

            for (int end = 0; end < N; ++end) {
                currentSum += A[end];

                // Adjust the start of the window until the currentSum is <= maxSum
                while (currentSum > maxSum && start <= end) {
                    currentSum -= A[start];
                    ++start;
                }

                // Count the number of valid subarrays ending at 'end'
                count += (end - start + 1);
            }

            return count;
        };

        // Count subarrays with sum in the range [L, R]
        return countSubarraysWithSumLessThanOrEqualTo(A, N, R) - countSubarraysWithSumLessThanOrEqualTo(A, N, L - 1);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends