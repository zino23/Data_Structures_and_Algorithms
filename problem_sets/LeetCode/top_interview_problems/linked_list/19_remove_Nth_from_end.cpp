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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy_head = new ListNode;
    dummy_head->next = head;
    unordered_map<int, ListNode *> map{{0, dummy_head}};
    int cnt = 1;
    for (auto i = head; i; i = i->next) {
      map[cnt++] = i;
    }

    /* Note: cnt == number of nodes + 1 */
    int target = cnt - n;
    auto node = map[target];
    auto pre_node = map[target - 1];
    pre_node->next = node->next;
    return dummy_head->next;
  }
};
