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
  ListNode* deleteDuplicationAll( ListNode* head ) {
    // Delete all duplicates e.g. [1, 2, 2, 3] -> [1, 3]
    // The head may be deleted, e.g. [1, 1, 2] -> [2], we can make a dummy head
    // pointing to head, then treat head as an internal node, and return
    // dummy->next
    auto dummy = new ListNode( -1 );  // dummy->val != head->val
    dummy->next = head;
    // We need a pointer *pre pointing to the ending node of the list of nodes
    // with no duplicates and a pair of pointers *st and *ed so the nodes from
    // *st to *ed are all duplicates Then if the number of duplicates are bigger
    // than 1, delete all nodes from *st to *ed. *pre does not need to change in
    // this case, and we simply assign ed->next to pre->next, and set st to
    // pre->next and repeat
    auto pre = dummy;
    auto st = pre->next;
    auto ed = st;

    // When pre->next == nullptr, pre points to the last node, we have processed
    // all the nodes
    while ( pre->next != nullptr ) {
      st = pre->next;
      // Increment ed starting from st
      ed = st;
      // Before we compare the value of ed->next and st, we have to make sure
      // ed->next is not nullptr E.g. [1, 2, 2, nullptr]
      //          |  |     |
      //         st ed  ed->next
      while ( ed->next != nullptr && ed->next->val == st->val ) {
        ed = ed->next;
      }

      // If the number of "duplicates" is one, find non duplicate node, set pre
      // to point to this node
      if ( st == ed ) {
        pre = ed;
      } else {
        // Find duplicates, pre does not change, update pre->next to ed->next,
        // i.e. delete all nodes from st to ed
        pre->next = ed->next;
      }
    }
    return dummy->next;
  }

  ListNode* deleteDuplicationLeaveOne( ListNode* head ) {
    // Leave one duplicate e.g. [1, 2, 2, 3] -> [1, 2, 3]
    // The head will not be deleted, it is still easier to code with a dummy
    // head
    auto dummy = new ListNode( -1 );
    dummy->next = head;
    auto pre = dummy;
    auto st = pre->next;
    auto ed = st;
    while ( pre->next ) {
      st = pre->next;
      ed = st;
      while ( ed->next && ed->next->val == st->val ) {
        ed = ed->next;
      }
      pre->next = ed;
      pre = ed;
    }
    return dummy->next;
  }
};

int main() {
  ListNode* a = new ListNode( 1 );
  ListNode* b = new ListNode( 2 );
  ListNode* c = new ListNode( 2 );
  ListNode* d = new ListNode( 3 );
  a->next = b, b->next = c, c->next = d;
  Solution s = Solution();
  s.deleteDuplicationAll( a );
  for ( auto i = a; i; i = i->next ) {
    cout << i->val << ' ';
  }
  cout << endl;

  // s.deleteDuplicationLeaveOne( a );
  // for ( auto i = a; i; i = i->next ) {
  //   cout << i->val << ' ';
  // }
  // cout << endl;
  return 0;
}

