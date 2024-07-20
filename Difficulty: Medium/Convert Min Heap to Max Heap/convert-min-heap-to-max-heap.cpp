//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <algorithm>

class Solution {
public:
    void convertMinToMaxHeap(std::vector<int> &arr, int N) {
        // Build Max-Heap from the array
        for (int i = (N / 2) - 1; i >= 0; i--) {
            heapify(arr, N, i);
        }
    }

private:
    void heapify(std::vector<int> &arr, int N, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left = 2*i + 1
        int right = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (left < N && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < N && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            std::swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, N, largest);
        }
    }
};



//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends