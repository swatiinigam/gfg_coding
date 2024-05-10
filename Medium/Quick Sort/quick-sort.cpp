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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high) {
            // calling partition function.
            int p = partition(arr, low, high);
            // calling quicksort function for the left of pivot.
            quickSort(arr, low, p - 1);
            // calling quicksort function for the right of pivot.
            quickSort(arr, p + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Taking first element as pivot.
       int pivot = arr[low];
       int i = low + 1; // Index of smaller element
       for (int j = low + 1; j <= high; j++)
       {
           // If current element is smaller than the pivot
           if (arr[j] < pivot)
           {
               // Swap arr[i] and arr[j]
               swap(arr[i], arr[j]);
               i++; // Increment index of smaller element
           }
       }
       // Swap arr[low] and arr[i-1] (or pivot)
       swap(arr[low], arr[i - 1]);
       return (i - 1);
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