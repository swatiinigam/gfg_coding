class Solution {
  public:
    int getLPSLength(string &s) {
               
                int n = s.size();
                int maxi =0;
                vector<int>idx;
                 
                for(int i=n-2;i>=0;i--){
                      if (s[i]==s[n-1]){
                             
                                    //   cout<<i<<" "<<n-i<<" ";  /                
                         string k = s.substr(0,i+1);
                         string m = s.substr(n-i-1,i+1);
                         
                         if (k==m){
                              return i+1;
                              
                         }
                               
                            
                      }
                } 
                
                return 0;
                 
                 
            
                 
                
    }
};