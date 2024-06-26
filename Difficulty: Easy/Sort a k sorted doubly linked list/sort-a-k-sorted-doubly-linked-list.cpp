//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
    // Function to sort a k-sorted doubly linked list
    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (!head) return head;

        // Step 1: Store all node values in a vector
        DLLNode* temp = head;
        vector<int> v;
        while (temp != nullptr) {
            v.push_back(temp->data);
            temp = temp->next;
        }

        // Step 2: Sort the vector
        sort(v.begin(), v.end());

        // Step 3: Put the sorted values back into the linked list
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->data = v[i++];
            temp = temp->next;
        }

        return head;
    }
};


//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data)
{
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head)
{
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a;
        cin >> a;
        DLLNode *head = new DLLNode(a);
        DLLNode *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            push(&tail, a);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends