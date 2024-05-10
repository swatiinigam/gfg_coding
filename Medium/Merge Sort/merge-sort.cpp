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
    void merge(int arr[], int l, int m, int r)
    {
         int len1 = m - l + 1;
         int len2 = r - m;
         int *arr1 = new int[len1];
         int *arr2 = new int[len2];
         
         for(int i = 0; i < len1; i++){
             arr1[i] = arr[l + i];
         }
         for(int j = 0; j < len2; j++){
             arr2[j] = arr[m + 1 + j];
         }
         
         int i = 0, j = 0, k = l;
         while(i < len1 && j < len2){
             if(arr1[i] <= arr2[j]){
                 arr[k] = arr1[i];
                 i++;
             }
             else{
                 arr[k] = arr2[j];
                 j++;
             }
             k++;
         }
         
         while(i < len1){
             arr[k] = arr1[i];
             i++;
             k++;
         }
         while(j < len2){
             arr[k] = arr2[j];
             j++;
             k++;
         }
         
         delete[] arr1;
         delete[] arr2;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l < r){
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};


//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends