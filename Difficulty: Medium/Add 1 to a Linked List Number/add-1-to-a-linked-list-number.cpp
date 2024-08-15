//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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
private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* forw = nullptr;
        while (curr != nullptr) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

public:
    Node* addOne(Node* head) {
        // Step 1: Reverse the list
        head = reverseList(head);

        Node* temp = head;
        Node* prev = nullptr;
        int carry = 1;  // Start with the carry of 1 (for adding one)

        // Step 2: Add one and handle carry
        while (temp != nullptr && carry > 0) {
            int sum = temp->data + carry;
            carry = sum / 10;  // Determine if there is a carry for the next node
            temp->data = sum % 10;  // Update current node data with new value
            prev = temp;  // Keep track of the last processed node
            temp = temp->next;
        }

        // If there is still carry left, we need to add a new node at the end
        if (carry > 0) {
            prev->next = new Node(carry);
        }

        // Step 3: Reverse the list back to original order
        head = reverseList(head);
        return head;
    }
};

//{ Driver Code Starts.

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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends