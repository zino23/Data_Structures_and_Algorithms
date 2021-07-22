#include <cstddef>
#include <iostream>

using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ListNode *reverseListIter(ListNode *head);
  ListNode *reverseListRecur(ListNode *head);
};

ListNode *ListNode::reverseListIter(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *next = nullptr;
  /**
   * The iterative version: backward update
   *
   * Needs to maintain a prev and next pointer mannually, and each update will
   * set current node->next to prev
   */
  for (auto i = head; i != nullptr;) {
    next = i->next;
    i->next = prev;
    prev = i;
    i = next;
  }
  return prev;
}

ListNode *ListNode::reverseListRecur(ListNode *head) {
  /* base case, when next pointer is nullptr, current node is the new head */
  if (!head || !head->next) {
    return head;
  }

  /**
   * The recuresive version: forward update
   *
   * In each recuresive call, set current node->next->next to node
   */
  auto new_head = reverseListRecur(head->next);
  head->next->next = head;
  head->next = nullptr;
  return new_head;
}

int main() { return 0; }
