//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class Node {
    public:
    int key, value;
    Node *next;
    Node *prev;
    
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
  int cap;
  Node *cache;
  unordered_map<int, Node *> mp;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int _cap) {
        // code here
        cap = _cap;
        cache = new Node(-1, -1);
        cache -> next = cache;
        cache -> prev = cache;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp.find(key) == mp.end()) return -1;
        Node *node = mp[key];
        Node *prev = node -> prev, *next = node -> next;
        // Segregation
        prev -> next = next;
        next -> prev = prev;
        
        Node *temp = cache -> next;
        
        // Addition to the front
        cache -> next = node;
        node -> next = temp;
        
        temp -> prev = node;
        node -> prev = cache;
        
        
        return node -> value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        
        Node *newNode = NULL;
        
        if(mp.find(key) != mp.end()) {
            mp[key] -> value = value;
            newNode = mp[key];
            
            Node *prev = newNode -> prev, *next = newNode -> next;
            
            // Segregation
            prev -> next = next;
            next -> prev = prev;
            
        } else {
            newNode = new Node(key, value);
            if(mp.size() == cap) {
                Node *rem = cache -> prev;
                rem -> prev -> next = cache;
                cache -> prev = rem -> prev;
                
                rem -> prev = NULL; rem -> next = NULL;
                
                //cout << "\nremove : " << rem -> key << endl;
                mp.erase(rem -> key);
                
                delete rem;
                
            }
            
            mp[key] = newNode;
        }
        
        Node *next = cache -> next;
        
        cache -> next = newNode;
        newNode -> prev = cache;
        
        newNode -> next = next;
        next -> prev = newNode;
        
        
        return;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends