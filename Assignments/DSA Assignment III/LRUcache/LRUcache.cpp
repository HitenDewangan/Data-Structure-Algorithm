#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // Stores key -> Node mapping
    Node* head; // Dummy head of the linked list
    Node* tail; // Dummy tail of the linked list

    // Removes a node from the linked list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Adds a node right after the head
    void add(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

public:
    // Initializes the cache with a given capacity
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);  // Create dummy head
        tail = new Node(0, 0);  // Create dummy tail
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // Returns the value of the key if present, otherwise -1
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            add(node);
            return node->value;
        }
        return -1;
    }

    // Adds or updates the key-value pair
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            node->value = value;
            add(node);
        } else {
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            add(node);
            cache[key] = node;
        }
    }
};

// Example usage
int main() {
    LRUCache lru_cache(2);
    lru_cache.put(1, 1);
    lru_cache.put(2, 2);
    cout << lru_cache.get(1) << endl;  // 1
    lru_cache.put(3, 3);  // Evicts key 2
    cout << lru_cache.get(2) << endl;  // -1 (not found)
    lru_cache.put(4, 4);  // Evicts key 1
    cout << lru_cache.get(1) << endl;  // -1 (not found)
    cout << lru_cache.get(3) << endl;  // 3
    cout << lru_cache.get(4) << endl;  // 4
    return 0;
}
