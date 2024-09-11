//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        long long currel=0;
        long long sum=0;
        while(pq.size()>=2){
            long long a =pq.top();
            pq.pop();
            long long b =pq.top();
            pq.pop();
            currel=a+b;
            sum+=currel;
            pq.push(currel);
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends