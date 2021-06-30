// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    auto new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }

  ListNode* reversListSeq(ListNode* head) {
    if (head == nullptr) return nullptr;
    auto i = head;
    ListNode* pre = nullptr;
    for (; i;) {
      auto next = i->next;
      i->next = pre;
      pre = i;
      i = next;
    }
    return pre;
  }
};

int main() {
  Solution S;
  auto l1 = new ListNode(1);
  S.reversListSeq(l1);
  return 0;
}
