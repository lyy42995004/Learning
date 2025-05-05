#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
    int key, value;
    Node* next, *prev;
    Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
    Node(int key_, int value_)
    : key(key_), value(value_),  next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : size_(0), capacity_(capacity) {
        head_ = new Node();
        tail_ = new Node();
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        Node* cur = head_;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    
    int get(int key) {
        if (!hash_.count(key)) {
            return -1;
        }
        Node* node = hash_[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (hash_.count(key)) {
            Node* node = hash_[key];
            node->value = value;
            moveToHead(node);
        } else {
            size_++;
            Node* node = new Node(key, value);
            hash_[key] = node;
            addToHead(node);
            if (size_ > capacity_) {
                Node* tail = removeTail();
                hash_.erase(tail->key);
                delete tail;
                size_--;
            }
        }
    }

private:
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        Node* head = head_->next;
        head_->next = node;
        node->prev = head_;
        node->next = head;
        head->prev = node;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail() {
        Node* tail = tail_->prev;
        removeNode(tail);
        return tail;
    }

private:
    Node* head_, *tail_;
    unordered_map<int, Node*> hash_;
    int size_, capacity_;
};

int main() {
    LRUCache* lrucache = new LRUCache(2);

    // 1 -1 -1 3 4
    lrucache->put(1, 1);                // 缓存是 {1=1}
    lrucache->put(2, 2);                // 缓存是 {1=1, 2=2}
    cout << lrucache->get(1) << " ";    // 返回 1
    lrucache->put(3, 3);                // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lrucache->get(2) << " ";    // 返回 -1 (未找到)
    lrucache->put(4, 4);                // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lrucache->get(1) << " ";    // 返回 -1 (未找到)
    cout << lrucache->get(3) << " ";    // 返回 3
    cout << lrucache->get(4) << " ";    // 返回 4
    cout << endl;

    return 0;
}