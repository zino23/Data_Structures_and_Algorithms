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
    auto dummy = new ListNode(-1);
    /**
     * @tail: the end node of the new list
     * @l1: the first unadded node in l1
     * @l2: the first unadded node in l2
     */
    auto tail = dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    while (l1) {
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }

    while (l2) {
      tail->next = l2;
      l2 = l2->next;
      tail = tail->next;
    }

    return dummy->next;
  }
};
