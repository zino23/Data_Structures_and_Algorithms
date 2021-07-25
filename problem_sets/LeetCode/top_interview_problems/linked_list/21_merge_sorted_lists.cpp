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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 && !l2) {
      return nullptr;
    }

    if (l1 && !l2) {
      return l1;
    }

    if (!l1 && l2) {
      return l2;
    }

    auto i = l1, j = l2;
    auto dummy_head = new ListNode;
    ListNode *k = dummy_head;
    while (i && j) {
      if (i->val <= j->val) {
        k->next = i;
        i = i->next;
      } else {
        k->next = j;
        j = j->next;
      }
      k = k->next;
    }

    while (i) {
      k->next = i;
      i = i->next;
      k = k->next;
    }

    while (j) {
      k->next = j;
      j = j->next;
      k = k->next;
    }
    return dummy_head->next;
  }
};
