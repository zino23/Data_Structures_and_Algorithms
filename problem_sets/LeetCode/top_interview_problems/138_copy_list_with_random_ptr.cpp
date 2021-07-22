// Definition for a Node.
#include <cstddef>
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }

    /**
     * 1. Create a deep copy without random ptr
     * 2. Create a hashmap: map[old_node] = new_node
     */
    auto new_head = new Node(head->val);
    unordered_map<Node *, Node *> map;
    auto node = new_head;
    for (auto i = head; i != nullptr; i = i->next) {
      map[i] = node;
      if (i->next != nullptr) {
        node->next = new Node(i->next->val);
      }
      node = node->next;
    }

    /* Fill random ptr for each node */
    for (auto i = head; i != nullptr; i = i->next) {
      if (i->random != nullptr) {
        map[i]->random = map[i->random];
      }
    }
    return new_head;
  }
};
