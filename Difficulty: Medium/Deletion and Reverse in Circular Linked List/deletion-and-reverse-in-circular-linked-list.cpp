//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    /* structure for a node
    struct Node
    {
        int data;
        struct Node *next;
    };
    */

    /* Function to delete a given node from the list */
   void deleteNode(struct Node **head, int key) {
    Node* temp = *head;

    // Case 1: If the list is empty
    if (temp == nullptr) {
        return;
    }

    // Case 2: If the node to be deleted is the head node
    if (temp->data == key) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp->next;
        *head = temp->next;
        delete temp;
        return;
    }

    // Case 3: Traverse the list to find the node to be deleted
    Node* prev = nullptr;
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != key);

    // If key is not present in the list
    if (temp == *head) {
        return;
    }

    // Case 4: Node with key found, unlink it from the list
    prev->next = temp->next;
    delete temp;
}
void reverse(struct Node** head_ref) {
    Node* curr = *head_ref;
    Node* prev = nullptr;
    Node* next = nullptr;

    // Case 1: If the list is empty
    if (curr == nullptr) {
        return;
    }

    // Case 2: Regular reversal of the linked list
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != *head_ref);

    // Adjust the head pointer to point to the new head
    (*head_ref)->next = prev;
    *head_ref = prev;
}
};

//{ Driver Code Starts.

/* Function to print nodes in a given
circular linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    } else
        cout << "empty" << endl;

    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular
        Solution ob;
        ob.deleteNode(&head, key);
        ob.reverse(&head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends