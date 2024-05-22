//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    vector<int> preorder;
public:
    
    void Helper(vector<int>& nums,int i,int j){
        if(i>j)return;
        int mid = (i+j)/2;
        preorder.push_back(nums[mid]);
        Helper(nums,i,mid-1);
        Helper(nums,mid+1,j);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        Helper(nums,0,nums.size()-1);
        return preorder;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends