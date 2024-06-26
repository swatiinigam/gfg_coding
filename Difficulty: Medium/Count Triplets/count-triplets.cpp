//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    //we can u 3 sum first store all node val in vector
    Node*temp=head;
    vector<int>v;
    while(temp!=nullptr){
        v.push_back(temp->data);
        temp=temp->next;
    }
    //now three sum 
    
    sort(v.begin(),v.end());
    int n=v.size();
    int cnt=0;
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
            int currsum=v[i]+v[left]+v[right];
            if(currsum==x){
                cnt++;
                left++;
                right--;
            }
            else if(currsum<x){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return cnt;
} 