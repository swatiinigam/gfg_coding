//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       bool isnegative = (s1[0] == '-') ^ (s2[0] == '-');
       
       if(s1[0] == '-') s1 = s1.substr(1);
       if(s2[0] == '-') s2 = s2.substr(1);
       
       while(s1.size() > 1 && s1[0] == '0'){
           s1.erase(0 , 1);
       }
       while(s2.size() > 1 && s2[0] == '0'){
           s2.erase(0 , 1);
       }
       
       if(s1 == "0" || s2 == "0") return "0";
       
       int n1 = s1.size();
       int n2 = s2.size();
       
       vector<int> result(n1 + n2 , 0);
       
       for(int i=n1-1;i>=0;i--){
           for(int j=n2-1;j>=0;j--){
               int mul = (s1[i] - '0') * (s2[j] - '0');
               int sum = mul + result[i + j + 1];
               result[i+j+1] = sum % 10;
               result[i+j] += sum / 10;
           }
       }
       
       string prod = "";
       
       for(auto num : result){
           if(!(prod.empty() && num == 0)){
               prod.push_back(num + '0');
           }
       }
       
       if(isnegative){
           prod.insert(prod.begin() , '-');
       }
       return prod;
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends