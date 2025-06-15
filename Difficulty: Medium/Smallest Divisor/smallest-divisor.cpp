class Solution {
  public:
  
      bool is(int mid ,vector<int>&arr,int k){
           
                int total =0;
                
                for(int i:arr){
                      
                      int check = (i+mid-1)/mid;
                      
                      total+=check;
                      
                      if (total>k){
                           return false;
                      }
                       
                      
                }
                
                
                return true;
             
           
      }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
            sort(arr.begin(),arr.end());
            int n =arr.size();
            
            int i=1;
            int maxi =*max_element(arr.begin(),arr.end());
            int j=maxi;
            int ans  =0;
            while (i<=j){
                  
                  int mid =i+(j-i)/2;
                  
                //   int number =mid;
                  if (is(mid ,arr, k)) {
                        ans =mid;
                        j=mid-1;
                  }
                  else{
                          i=mid+1; 
                  }
                  
            }
            
            return ans;
    
    
    
    }
};
