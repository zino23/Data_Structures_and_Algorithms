#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list with a random pointer
struct ListNode {
  int val;
  ListNode *next, *random;
  ListNode( int x ) : val( x ), next( NULL ), random( NULL ) {}
};

class Solution {
 public:
  ListNode *copyRandomListWithMap( ListNode *head ) {
    if ( !head ) return nullptr;
    unordered_map<ListNode *, ListNode *> map;
    auto new_head = new ListNode( head->val );
    map[head] = new_head;
    auto cur = new_head;
    for ( auto i = head->next; i; i = i->next, cur = cur->next ) {
      cur->next = new ListNode( i->val );
      map[i] = cur->next;
    }

    cur = head;
    for ( auto i = head; i; i = i->next, cur = cur->next ) {
      if ( i->random ) {
        cur->random = map[i->random];
      }
    }
    return new_head;
  }

  ListNode *copyRandomList( ListNode *head ) {
    auto cur = head;
    while ( cur ) {
      auto new_cur = new ListNode( cur->val );
      new_cur->next = cur->next;
      cur->next = new_cur;
      cur = new_cur->next;
    }

    for ( auto p = head; p; p = p->next->next ) {
      if ( p->random ) {
        p->next->random = p->random->next;
      }
    }

    // Extract the new list
    auto dummy = new ListNode( -1 );
    cur = dummy;
    for ( auto p = head; p; p = p->next ) {
      cur->next = p->next;
      cur = cur->next;
      p->next = cur->next;
    }
    return dummy->next;
  }
};
