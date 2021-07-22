/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    auto dummy_head = new ListNode;
    dummy_head->next = head;
    ListNode *begin, *end, *prev_begin, *after_end;
    int pos = 0;
    for (auto i = dummy_head; i != nullptr; i = i->next, ++pos) {
      if (pos == left - 1) {
        prev_begin = i;
        begin = i->next;
      }
      if (pos == right) {
        end = i;
        after_end = i->next;
        break;
      }
    }

    auto prev = after_end;
    ListNode* next;
    for (auto i = begin; i != after_end;) {
      next = i->next;
      i->next = prev;
      prev = i;
      i = next;
    }

    /**
     * Cos we use a dummy head, prev_begin will always be valid and the head is always
     * dummy_head->next
     */
    prev_begin->next = end;
    return dummy_head->next;
  }

  ListNode* reverseBetweenNoDummyHead(ListNode* head, int left, int right) {
    ListNode* prev = nullptr;
    ListNode* next;
    ListNode* begin;
    ListNode* end;
    ListNode* prev_begin;
    ListNode* after_end;
    int pos = 1;

    /**
     * Without dummy head, have to maintain *prev to get prev_begin. In the case left == 1, prev
     * will be nullptr
     */
    for (auto i = head; i != nullptr; i = i->next, ++pos) {
      if (pos == left) {
        begin = i;
        prev_begin = prev;
      }
      if (pos == right) {
        end = i;
        after_end = i->next;
        break;
      }
      prev = i;
    }

    /* Let begin->next == after_end */
    prev = after_end;
    for (auto i = begin; i != after_end;) {
      next = i->next;
      i->next = prev;
      prev = i;
      i = next;
    }

    /* When left == 1, prev_begin is nullptr */
    if (prev_begin) {
      prev_begin->next = end;
    }

    /* When left == 1, the new head is end */
    if (head == begin) {
      return end;
    }
    return head;
  }
};

int main() {
  auto n1 = new ListNode(1);
  auto n2 = new ListNode(2);
  auto n3 = new ListNode(3);
  auto n4 = new ListNode(4);
  auto n5 = new ListNode(5);
  // n1->next = n2;
  // n2->next = n3;
  // n3->next = n4;
  // n4->next = n5;
  auto s = new Solution;
  s->reverseBetween(n1, 1, 1);
  return 0;
}
