//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

class Solution {
public:
    // Function to find the first node where the loop starts in a linked list.
    Node* findFirstNode(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;

        // Detecting loop using Floyd’s Cycle-Finding Algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, there is a loop
            if (slow == fast) {
                break;
            }
        }

        // If no loop is found
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Move slow to head and keep fast at meeting point.
        // Move both one step at a time, they will meet at the start of the loop.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow (or fast) is now at the start of the loop
        return slow;
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
        int k;
        cin >> k;
        cin.ignore();
        assert(k <= arr.size());
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        Node *ans = ob.findFirstNode(head);
        cout << (ans == NULL ? -1 : ans->data) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends