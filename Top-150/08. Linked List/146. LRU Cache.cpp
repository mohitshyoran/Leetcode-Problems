Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



class LRUCache {
public:
    class Node {
        public:
            int key, val;
            Node* prev;
            Node* next;
            Node(int k, int v){
                key = k;
                val = v;
            }
    };
    int size;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            deleteNode(curr);
            addNode(curr);
            return curr->val;
        } 
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }

        if(mp.size() == size){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* temp = new Node(key, value);
        mp[key] = temp;
        addNode(temp);
    }
};
