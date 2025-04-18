//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends

class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high) {
            // calling partition function.
            int p = partition(arr, low, high);
            // calling quicksort function for the left of pivot.
            quickSort(arr, low, p - 1);
            // calling quicksort function for the right of pivot.
            quickSort(arr, p + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Taking first element as pivot.
        int pivot = arr[low];
        int cnt = 0;

        // Counting elements smaller than the pivot.
        for (int i = low + 1; i <= high; i++) {
            if (arr[i] <= pivot) {
                cnt++;
            }
        }

        // Pivot index after rearranging elements.
        int pivotIndex = low + cnt;
        
        // Placing pivot at its correct position.
        swap(arr[low], arr[pivotIndex]);

        // Partitioning: ensuring left side smaller and right side greater.
        int i = low;
        int j = high;

        while (i < pivotIndex && j > pivotIndex) {
            // Moving i forward if element is smaller than or equal to pivot.
            while (arr[i] <= pivot) {
                i++;
            }
            // Moving j backward if element is greater than pivot.
            while (arr[j] > pivot) {
                j--;
            }
            // Swap elements if i is still to the left of pivotIndex and j is to the right.
            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        return pivotIndex;
    }
};



//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends