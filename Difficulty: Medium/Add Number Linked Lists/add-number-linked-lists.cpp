//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
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

class Solution {
  public:
    Node* reverse(Node *head){
        Node *prev = NULL;
        Node *curr = head;
        
        while(curr){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        if(!num1) return num2;
        if(!num2) return num1;
        
        while(num1->next && num1->data == 0) num1 = num1->next;
        while(num2->next && num2->data == 0) num2 = num2->next;
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node *ans = new Node(-1);
        Node *mptr = ans;
        Node *ptrA = num1;
        Node *ptrB = num2;
        
        int carry = 0;
        
        while(ptrA && ptrB){
            int sum = ptrA->data + ptrB->data + carry;
            int digit = sum%10;
            carry = sum/10;
            
            mptr->next = new Node(digit);
            mptr = mptr->next;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        
        while(ptrA){
            int sum = ptrA->data + carry;
            int digit = sum%10;
            carry = sum / 10;
            
            mptr->next = new Node(digit);
            mptr = mptr->next;
            ptrA = ptrA->next;
        }
        
        while(ptrB){
            int sum = ptrB->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            mptr->next = new Node(digit);
            mptr = mptr->next;
            ptrB = ptrB->next;
        }
        
        if(carry != 0){
            mptr->next = new Node(carry);
        }
        return reverse(ans->next);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends