//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
         vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        
        sort(v.begin(),v.end());
        vector<int>temp;
         temp.push_back(v[0].first);
        for(int i =0;i<n;i++){
           if(v[i].second >temp.back()){
               temp.push_back(v[i].first);
           }
        }
        return temp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends