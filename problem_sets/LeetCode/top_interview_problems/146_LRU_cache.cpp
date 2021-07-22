#include <iostream>
#include <memory>
#include <mutex>
#include <unordered_map>

using namespace std;

class Node {
 public:
  Node() : val_(-1), key_(-1), next(nullptr), prev(nullptr) {}
  Node(int key, int val) : key_(key), val_(val), next(nullptr), prev(nullptr) {}

  int key_;
  int val_;
  Node* next;
  Node* prev;
};

class LRUCache {
 public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    head_ = move(make_unique<Node>(-1, -1));
    tail_ = move(make_unique<Node>(-1, -1));
    head_->next = tail_.get();
    tail_->prev = head_.get();
  }

  int get(int key) {
    std::lock_guard<std::mutex> lock(lock_);

    if (k2node.find(key) == k2node.end()) {
      return -1;
    }

    auto node = k2node[key].get();
    moveToHead(node);
    return node->val_;
  }

  void put(int key, int value) {
    std::lock_guard<std::mutex> lock(lock_);

    // Cache not full, add a new node to head
    if (k2node.empty()) {
      k2node[key] = move(make_unique<Node>(key, value));
      addToHead(k2node[key].get());
      return;
    }

    // Key exists, update value and move to head
    if (k2node.find(key) != k2node.end()) {
      auto node = k2node[key].get();
      node->val_ = value;
      moveToHead(node);
      return;
    }

    // Cache is full, pop the tail node which is the LRU
    // Remove tail from linked list and k2node
    if (k2node.size() == capacity_) {
      auto tail = tail_->prev;
      removeNode(tail);
      k2node.erase(tail->key_);

      // Add new node to head
      k2node[key] = move(make_unique<Node>(key, value));
      addToHead(k2node[key].get());
      return;
    }
    k2node[key] = move(make_unique<Node>(key, value));
    addToHead(k2node[key].get());
  }

  void addToHead(Node* node) {
    node->prev = head_.get();
    node->next = head_->next;
    head_->next->prev = node;
    head_->next = node;
  }

  void moveToHead(Node* node) {
    removeNode(node);
    addToHead(node);
  }

  // Only remove from linked list
  void removeNode(Node* node) {
    // Due to the existence of dummy head and tail, we can simply do the following
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  // Dummy head and tail
  unique_ptr<Node> head_;
  unique_ptr<Node> tail_;
  // Owns the nodes
  unordered_map<int, unique_ptr<Node>> k2node;
  int capacity_;
  std::mutex lock_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  auto lru = make_unique<LRUCache>(2);
  lru->put(2, 1);
  lru->put(2, 2);
  cout << lru->get(2) << endl;
  lru->put(1, 1);
  lru->put(4, 1);
  cout << lru->get(2) << endl;
  return 0;
}
