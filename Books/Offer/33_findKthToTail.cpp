#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
 public:
  ListNode* findKthToTail( ListNode* pListHead, int k ) {
    // Reverse
    auto cur = pListHead;
    ListNode* last = nullptr;
    while ( cur ) {
      auto ori_next = cur->next;
      cur->next = last;
      last = cur;
      cur = ori_next;
    }
    auto new_head = last;
    int i = 1;
    for ( auto p = new_head; p; p = p->next, i++ ) {
      if ( i == k ) {
        return p;
      }
    }
    return nullptr;
  }
};

int main()

