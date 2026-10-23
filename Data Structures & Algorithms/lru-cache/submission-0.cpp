class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node -> prev;
        Node* nxt = node -> next;
        prev -> next = nxt;
        nxt -> prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right -> prev;
        prev -> next = node;
        node -> prev = prev;

        right -> prev = node;
        node -> next = right;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left -> next = right;
        right -> prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node -> val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left -> next;
            cache.erase(lru -> key);
            remove(lru);
            delete lru;
        }
    }
};
