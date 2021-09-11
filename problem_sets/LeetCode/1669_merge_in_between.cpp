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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    auto dummy = new ListNode(-1);
    dummy->next = list1;
    // dummy->0->1->2->..->8->..->n
    //              ^      ^
    //             a=2    b=8
    int cnt = 0;
    ListNode *before = nullptr;
    ListNode *after = nullptr;
    for (auto i = list1; i; i = i->next) {
      if (cnt == a - 1) {
        before = i;
      } else if (cnt == b + 1) {
        after = i;
        break;
      }
      cnt++;
    }

    if (!a || !b) {
      return nullptr;
    }

    before->next = list2;

    while (list2->next) {
      list2 = list2->next;
    }

    list2->next = after;
    return dummy->next;
  }
};
