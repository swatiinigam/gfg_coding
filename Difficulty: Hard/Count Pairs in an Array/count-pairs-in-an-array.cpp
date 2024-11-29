//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(int arr[],int low,int mid,int high)
    {
        int temp[high-low+1];
        int left=low;
        int right=mid+1;
        int cnt=0;
        int i=0;
        while(left <=mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp[i++]=arr[left];
                left++;
            }
            else{
                cnt=cnt+(mid-left+1);
                temp[i++]=arr[right];
                right++;
            }
        }
        while(left <= mid)
        {
            temp[i++]=arr[left++];
        }
        while(right <= high)
        {
            temp[i++]=arr[right++];
        }
        for(int j=low;j<=high;j++)
        {
            arr[j]=temp[j-low];
        }
        return cnt;
    }
    int mergeSort(int arr[],int low,int high)
    {
        int cnt=0;
        if(low >= high) return 0;
        int mid=(low+high)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
    
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]*i;
        }
        return mergeSort(arr,0,n-1);
    }
};



//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends