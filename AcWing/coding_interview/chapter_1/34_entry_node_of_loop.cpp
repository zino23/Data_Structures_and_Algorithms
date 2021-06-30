// Definition for singly-linked list.
#include <cstddef>
#include <unordered_map>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *entryNodeOfLoop(ListNode *head) {
    unordered_map<ListNode *, bool> map;
    for (auto i = head; i; i = i->next) {
      if (map.find(i) != map.end())
        return i;
      map.insert({i, true});
    }
    return nullptr;
  }
};
