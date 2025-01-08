//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head)
    {
        Node* p=head;
        Node* q=NULL;
        Node* r=NULL;
        
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    Node* middle(Node* head)
    {
        Node* p=head;
        Node* q=head;
        while(q && q->next)
        {
            p=p->next;
            q=q->next;
            if(q!=NULL)
                q=q->next;
        }
        return p;
    }
    Node* reorder(Node* first,Node* second)
    {
        Node* third=first;
        Node* last=first;
        
        while(first!=NULL && second!=NULL)
        {
            first=first->next;
            last->next=second;
            last=second;
            second=second->next;
            last->next=first;
            last=first;
        }
        return third;
    }
    void reorderList(Node* head) 
    {
        Node* first=head;
        Node* x=middle(head);
        Node* second=x->next;
        x->next=NULL;
        second=reverse(second);
        
        reorder(first,second);
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends