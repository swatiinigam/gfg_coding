/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        if(!head){
            Node* newNode=new Node(data);
            newNode->next=newNode;
            return newNode;
        }
        if(head->data>data){
            Node* node=head;
            while(node->next!=head){
                node=node->next;
            }
            Node* newNode=new Node(data);
            node->next=newNode;
            newNode->next=head;
            return newNode;
        }
        
        Node* node=head->next, *prev=head;
        while(node->data<data && node!=head){
            prev=node;
            node=node->next;
        }
        Node* newNode=new Node(data);
        prev->next=newNode;
        newNode->next=node;
        return head;
    }
};