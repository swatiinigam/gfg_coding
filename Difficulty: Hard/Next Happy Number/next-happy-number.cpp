//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int squareSum(int num) {
        int sum = 0;
        while(num) {
            sum += (num%10)*(num%10);
            num /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        set<int> s;
        
        while(true) {
            n = squareSum(n);
            if(n == 1)
                return true;
            else if(s.find(n) != s.end())
                return false;
            s.insert(n);
        }
    }
    
    int nextHappy(int N) {
        while(true) {
            N++;
            if(isHappy(N))
                return N;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends