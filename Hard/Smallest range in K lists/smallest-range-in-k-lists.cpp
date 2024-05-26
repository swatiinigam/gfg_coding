//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range


class Solution{
    public:
    // Node class representing an element and its position in the 2D array
    class node {
        public:
        int data;
        int row;
        int col;
        
        // Constructor to initialize the node
        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
    };
    
    // Comparator class for the priority queue
    class compare {
        public:
        // Overloading the '()' operator for comparison
        bool operator()(node* a, node* b) {
            return a->data > b->data; // Min-heap based on data
        }
    };
    
    // Method to find the smallest range
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          // Initialize variables
          int mini = INT_MAX, maxi=INT_MIN;
          priority_queue<node*, vector<node*>, compare > pq;
          
          // Push the first element of each list into the priority queue
          for(int i=0; i<k; i++) {
              int element = KSortedArray[i][0];
              mini = min(mini,element);
              maxi = max(maxi,element);
              pq.push(new node(element,i,0));
          }
          
          // Set the initial range
          int start = mini , end = maxi;
          
          // Main loop to find the smallest range
          while(!pq.empty())
          {
              // Get the smallest element and its position
              node* temp = pq.top();
              pq.pop();
              mini = temp->data;
              
              // Update the range if a smaller one is found
              if(maxi-mini < end - start)
              {
                  start = mini;
                  end = maxi;
              }
              
              // Check for the next element in the same row
              if(temp -> col + 1 < n)
              {
                  // Update maxi and push the next element into the queue
                  maxi = max(maxi,KSortedArray[temp->row][temp->col + 1]);
                  pq.push(new node(KSortedArray[temp->row][temp->col + 1],
                  temp->row, temp -> col + 1));
              }
              else 
                break; // Break if there is no next element
          }
          
          // Return the smallest range found
          return {start,end};
    }
};






//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends