//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        if(head == NULL || head->next == NULL)
         return head;
         
        Node* tmp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return tmp;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        int sum = 0;
        int carry = 0;
        
        Node* head = NULL;
        
        while(num1 || num2){
            sum = 0;
            if(num1){
                sum+=num1->data;
                num1 = num1->next;
            }
            if(num2){
                sum+=num2->data;
                num2 = num2->next;
            }
            
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            
            Node* tmp = new Node(sum);
            tmp->next = head;
            head = tmp;
        }
        
        if(carry>0){
            Node* tmp = new Node(carry);
            tmp->next = head;
            head = tmp;
        }
        
        while(head->next && head->data == 0){
            head = head->next;
        }
        
        return head;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends