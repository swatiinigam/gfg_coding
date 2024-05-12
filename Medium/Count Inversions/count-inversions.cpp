//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long i, j, k;
        long long inv_count = 0;

        i = left; // Index for left subarray
        j = mid; // Index for right subarray
        k = left; // Index for merged array

        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                inv_count += (mid - i); // Count inversions
            }
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return inv_count;
    }

    long long mergeSort(long long arr[], long long temp[], long long left, long long right) {
        long long mid, inv_count = 0;
        if (right > left) {
            mid = (right + left) / 2;
            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    long long int inversionCount(long long arr[], long long N) {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }
};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends