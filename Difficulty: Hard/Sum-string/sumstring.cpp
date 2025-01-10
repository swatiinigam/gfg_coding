//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string add(string a, string b){
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i=0, c = 0;i<a.size()||i<b.size()||c;i++){
            int x = i<a.size()?a[i]-'0':0, y = i<b.size()?b[i]-'0':0, s = (x + y + c)%10;
            c = (x + y + c) > 9;
            ans.push_back(s+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int isSumString(string s){
        for (int i = 0;i<(int)s.size()-1;i++)
            for (int j = i+1;j<s.size()-1;j++)
            {
                int a = j, b = i, c = 0;
                while(true){
                    int check = 1;
                    string res = add(s.substr(c, b-c+1), s.substr(b+1, a-b));
                    for (int k = 0,z = a+1;k<res.size();k++, z++ )
                        if (z>=s.size()||s[z]!=res[k]) check = 0;
                    if (!check) break;
                    c = b+1, b = a, a += res.size();
                    if (a>=s.size()-1) return 1;
                }
            }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends