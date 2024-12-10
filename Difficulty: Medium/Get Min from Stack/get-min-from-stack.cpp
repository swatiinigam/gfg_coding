//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s1;
    stack<int> s2;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s1.empty()){
               return -1;
           }
           return s2.top();
         
       }
       
       /*returns poped element from stack*/
       int pop(){
           
               int x;
               if(s1.empty()){
                   return -1;
               }
               x=s1.top();
               if(s1.top()>s2.top())
               {
                   s1.pop();
               }
               else{
                   s1.pop();
                   s2.pop();
               }
               return x;
     
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s1.empty()){
               s1.push(x);
               s2.push(x);
           }
           else if(x>s2.top()){
               s1.push(x);
           }
           else{
               s1.push(x);
               s2.push(x);
           }
          
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends