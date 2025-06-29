class Solution {
  public:
    int func(vector<int>&arr,int mid)
    {
        int n=arr.size(),sum=0;
        int k=1;
        for(int i=0;i<n;i++)
        {
            if(sum+arr[i]>mid){
            sum=arr[i];
            k++;}
            else
            sum+=arr[i];
        }
        return k;
    }
    int splitArray(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int start=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int count=func(arr,mid);
            if(count<=k)
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};