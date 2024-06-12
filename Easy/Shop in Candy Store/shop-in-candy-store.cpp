//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int>ans;
        sort(candies,candies+N);
        int maxi=0;
        int mini=0;
        int i=0;
        int j=N-1;
        while(i<=j){
            mini+=candies[i];
            i++;
            j-=K;
        }
        int a=N-1;
        int b=0;
        while(a>=b){
            maxi+=candies[a];
            a--;
            b+=K;
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends