// practicing pointers
// practicing design in cpp
// working with struct, hashmap, doubly linked list
class LRUCache {
// private instance variables
private:
    struct Node {
        int key;
        int val;
        Node * prev;
        Node * next;
        
        // struct constructor, using member initializer list
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    // capacity
    int cap;
    // defining head of dll
    Node *lru;
    // defining tail of dll
    Node *mru;
    // mapping of keys to corresponding nodes in the doubly linked list
    std::unordered_map<int, Node*> cache;
public:
    // member initializer list
    LRUCache(int capacity): cap(capacity) {
        // inserting dummy nodes initially to avoid edge cases
        lru = new Node(0,0);
        mru = new Node(0,0);
        lru -> next = mru;
        mru -> prev = lru;
    }
//     LRUCache(int capacity) {
        
//     }
    
    
    // passing a pointer to node
    // issue = When removing, freeing node, just not do that? will get reassigned anyway
    void remove(Node* node) {
        // std::cout << "remove" << std::endl;
        // std::cout << node -> key << std::endl;
        // print_list();
        
        // dll remove
        Node* prev_node = node -> prev;
        Node* next_node = node -> next;
        prev_node -> next = next_node;
        next_node -> prev = prev_node;
        
        // std::cout << "list after remove" << std::endl;
        // print_list();
        // std::cout << std::endl;
        
    }
    
    // insert node in front of mru 
    void insert(Node* node) {
        // std::cout << "insert" << std::endl;
        // print_list();
        Node* prev_node = mru -> prev;
        // Node* next_node = mru;
        node -> next = mru;
        node -> prev = prev_node;
        prev_node -> next = node;
        mru -> prev = node;
        
            
        // std::cout << "after insert" << std::endl;
        // print_list();
        // std::cout << std::endl;
    }
    
    // a get is an access, so have to reinsert node
    int get(int key) {
        // std::cout << "get" << std::endl;
        // std::cout << key << std::endl;
        // print_cache();
        // have to update the node position 
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            int val = node -> val;
            remove(node);
            insert(node);
            return val;
        }
        
        // std::cout << std::endl;
        return -1;
    }
    
    void put(int key, int value) {
        // std::cout << "put" << std::endl;
        // std::cout << lru -> next -> key <<std::endl;
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        
        // Dynamically allocates heap memory for a node object and returns pointer. 
        cache[key] = new Node(key,value);
        insert(cache[key]);
        
        //std::cout << key << ", " << cache[key]->val << std::endl;
        
        if (cache.size() > cap) {
            // lru = lru -> next; This seems to be causing issues, fixing the dummy lru node instead
            cache.erase(lru -> next -> key);
            remove(lru -> next);
        }
        
        //std::cout << std::endl;
    }
    
    void print_cache() {
        std::cout << "Cache" << std::endl;
        for (const auto& entry : cache) {
            std::cout << entry.first << " ";// << ":" << (entry.second -> prev) -> key << ", "<< (entry.second -> next) -> key << std::endl;
        }
        std::cout << std::endl;
    }
    
    void print_list() {
       std::cout << "DLL" << std::endl;
       Node *curr = lru;
       
       while (curr) {
           std::cout << curr -> key << " ";
           curr = curr -> next;
       } 
        std::cout << std::endl;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */





// Debug 


        // node -> next = nullptr;
        // node -> prev = nullptr;
        // //free memory
        // delete node;
        // optional but recommended, Why?
        // node = nullptr;
        // print_cache();