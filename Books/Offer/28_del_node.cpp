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

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode( int x ) : val( x ), next( NULL ) {}
};

class Solution {
 public:
  void deleteNode( ListNode* node ) {
    // Copy the value of next node to current node
    node->val = node->next->val;
    // Delete next node
    node->next = node->next->next;
  }
};

int main()

