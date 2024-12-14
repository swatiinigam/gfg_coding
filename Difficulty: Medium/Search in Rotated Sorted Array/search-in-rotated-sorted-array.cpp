//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int pivotIndex(vector<int> arr)
    {
        int l=0,h=arr.size()-1;
        int ans=-1;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(arr[mid] < arr[mid+1] and arr[mid] < arr[mid-1]) return mid;
            else if(arr[mid] > arr[h]) l=mid+1;
            else
                h=mid-1;
        }
        
        return ans;
    }
    
    int binarySearch(vector<int>& arr, int key,int l,int h)
    {
        //int l=0,h=arr.size();
        int ans=-1;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(arr[mid] == key) return mid;
            else if(arr[mid] > key) h=mid-1;
            else
                l=mid+1;
        }
        
        return ans;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        
        int rotated_ind=pivotIndex(arr);
        int ind;
        //cout<<"rotated_ind:"<<rotated_ind<<'\n';
        if(rotated_ind!=-1)
        {
            ind=binarySearch(arr,key,0,rotated_ind-1);
            if(ind!=-1) return ind;
            else
                return binarySearch(arr,key,rotated_ind,arr.size()-1);
        }
        else
        return binarySearch(arr,key,0,arr.size()-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends