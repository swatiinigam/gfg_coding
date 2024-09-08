//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    long long merge(long long arr[], int l, int m, int r)
    {
         int len1 = m - l + 1;
         int len2 = r - m;
         long long *arr1 = new long long[len1];
         long long *arr2 = new long long[len2];
         long long cnt_inv = 0;
         
         // Copy data to temporary arrays
         for(int i = 0; i < len1; i++) {
             arr1[i] = arr[l + i];
         }
         for(int j = 0; j < len2; j++) {
             arr2[j] = arr[m + 1 + j];
         }
         
         int i = 0, j = 0, k = l;
         
         // Merge the arrays and count inversions
         while(i < len1 && j < len2) {
             if(arr1[i] <= arr2[j]) {
                 arr[k] = arr1[i];
                 i++;
             }
             else {
                 arr[k] = arr2[j];
                 cnt_inv += (len1 - i);  // All remaining elements in arr1 form an inversion with arr2[j]
                 j++;
             }
             k++;
         }
         
         // Copy remaining elements of arr1 (if any)
         while(i < len1) {
             arr[k] = arr1[i];
             i++;
             k++;
         }
         
         // Copy remaining elements of arr2 (if any)
         while(j < len2) {
             arr[k] = arr2[j];
             j++;
             k++;
         }
         
         delete[] arr1;
         delete[] arr2;
         
         return cnt_inv;
    }

    long long mergeSort(long long arr[], int l, int r)
    {
        long long cnt_inv = 0;
        if(l < r){
            int m = l + (r - l) / 2;
            cnt_inv += mergeSort(arr, l, m);
            cnt_inv += mergeSort(arr, m + 1, r);
            cnt_inv += merge(arr, l, m, r);
        }
        return cnt_inv;
    }
  
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        // Use merge sort to count inversions
        return mergeSort(arr, 0, n - 1);
    }
};


//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends