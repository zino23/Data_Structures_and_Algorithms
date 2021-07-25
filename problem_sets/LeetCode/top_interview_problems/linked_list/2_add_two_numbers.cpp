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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto res = new ListNode;
    auto i = l1, j = l2, k = res;
    int increment = 0, sum = 0;
    while (i && j) {
      sum = i->val + j->val + increment;
      k->val = sum % 10;
      increment = sum / 10;
      i = i->next;
      j = j->next;
      if (i || j || increment > 0) {
        k->next = new ListNode;
        k = k->next;
      }
    }

    // l1 > l2
    while (i) {
      sum = i->val + increment;
      k->val = sum % 10;
      increment = sum / 10;
      i = i->next;
      if (i || increment > 0) {
        k->next = new ListNode;
        k = k->next;
      }
    }

    // l2 > l1
    while (j) {
      sum = j->val + increment;
      k->val = sum % 10;
      increment = sum / 10;
      j = j->next;
      if (j || increment > 0) {
        k->next = new ListNode;
        k = k->next;
      }
    }

    // Still has increment
    if (increment > 0) {
      k->val = increment;
    }
    return res;
  }
};

