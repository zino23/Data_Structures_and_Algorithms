#include <iostream>
#include <unordered_map>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  using PLL = pair<ListNode *, ListNode *>;

  ListNode *reverseKGroup(ListNode *head, int k) {
    auto dummy = new ListNode(-1);
    dummy->next = head;
    /* Iterating tail */
    auto tail = dummy;
    auto before_head = dummy;
    while (tail != nullptr) {
      /* Head of to-be-reversed sublist */
      head = tail->next;
      ;
      for (int i = 0; i < k; i++) {
        tail = tail->next;
        // If cur is nullptr, the number of the last sequence of nodes is smaller than k
        if (tail == nullptr) {
          return dummy->next;
        }
      }

      // Need store this before reverse
      auto after_tail = tail->next;
      tie(head, tail) = reverseList(head, tail);

      // Patch the reversed sublist
      before_head->next = head;
      tail->next = after_tail;

      // Update before_head
      before_head = tail;
    }
    return dummy->next;
  }

  PLL reverseList(ListNode *head, ListNode *tail) {
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    auto after_tail = tail->next;
    auto cur = head;
    while (cur != after_tail) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    // new tail is the original head
    // new head is the original tail
    return {tail, head};
  }

  ListNode *reverseKGroupV2(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    unordered_map<int, ListNode *> map;
    int cnt = 0;
    auto node = dummy->next;
    while (node != nullptr) {
      cnt++;
      if (cnt % k == 1) {
        map[cnt] = node;
      }
      node = node->next;
    }

    if (cnt < k || k == 1) {
      return dummy->next;
    }

    // cnt is a multiple of k
    if (cnt % k == 0) {
      map[cnt + 1] = nullptr;
    }

    // each pair in q is {before_head, after_tail}
    map[1 - k] = dummy;
    for (int i = 1; i + k - 1 <= cnt; i = i + k) {
      reverseListV2(map[i], map[i - k], map[i + k]);
    }
    return dummy->next;
  }

  void reverseListV2(ListNode *head, ListNode *before_head, ListNode *after_tail) {
    auto prev = after_tail;
    ListNode *next = nullptr;
    while (head != after_tail) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    // @prev now points to the node before @after_tail
    before_head->next = prev;
  }
};

int main() {
  auto l1 = new ListNode(1);
  auto l2 = new ListNode(2);
  auto l3 = new ListNode(3);
  auto l4 = new ListNode(4);
  auto l5 = new ListNode(5);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  auto s = new Solution;
  s->reverseKGroup(l1, 2);
  return 0;
}
