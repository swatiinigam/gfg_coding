//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        int cntzero = 0, cntone = 0, cnttwo = 0;
        Node* temp = head;
        
        // Counting the number of 0s, 1s, and 2s
        while(temp != nullptr){
            if(temp->data == 1)
                cntone++;
            else if(temp->data == 0)
                cntzero++;
            else
                cnttwo++;
            temp = temp->next;
        }
        
        // Setting the data value of nodes
        temp = head;
        while(temp != nullptr){
            while(cntzero > 0){
                temp->data = 0;
                temp = temp->next;
                cntzero--;
            }
            while(cntone > 0){
                temp->data = 1;
                temp = temp->next;
                cntone--;
            }
            while(cnttwo > 0){
                temp->data = 2;
                temp = temp->next;
                cnttwo--;
            }
        }
        return head; 
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends