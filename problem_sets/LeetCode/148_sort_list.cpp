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
  ListNode *sortList(ListNode *head) {
    int n = 0;
    for (auto i = head; i; i = i->next) {
      n++;
    }

    auto dummy = new ListNode(-1);
    dummy->next = head;
    for (int i = 1; i < n; i *= 2) {
      auto cur = dummy;

      // Merge [first, ..], [second, ..]
      for (int j = 1; j + i <= n; j += 2 * i) {
        auto p = cur->next;
        auto q = p;
        // Find pos for second
        for (int k = 0; k < i; k++) {
          q = q->next;
        }

        // Merge
        int x = 0, y = 0;
        while (x < i && y < i && p && q) {
          if (p->val <= q->val) {
            cur->next = p;
            p = p->next;
            x++;
          } else {
            cur->next = q;
            q = q->next;
            y++;
          }
          cur = cur->next;
        }

        while (x < i && p) {
          cur->next = p;
          p = p->next;
          x++;
        }

        while (y < i && q) {
          cur->next = q;
          q = q->next;
          y++;
        }
        cur->next = q;
      }
    }
    return dummy->next;
  }
};

int main() {
  auto l1 = new ListNode(4);
  auto l2 = new ListNode(2);
  auto l3 = new ListNode(1);
  auto l4 = new ListNode(3);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  auto s = new Solution;
  s->sortList(l1);
  return 0;
}
