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
  ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0 || !head || !head->next) {
      return head;
    }

    int n = 1;
    auto t = head;
    while (t->next) {
      t = t->next;
      ++n;
    }

    int before_head = n - k % n;
    if (before_head == n) {
      return head;
    }

    /* t is the original tail */
    t->next = head;

    while (before_head--) {
      t = t->next;
    }

    /* t is new tail */
    auto res = t->next;
    t->next = nullptr;
    return res;
  }
};
