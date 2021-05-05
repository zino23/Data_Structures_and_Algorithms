class Solution {
 public:
  ListNode *findFirstCommonNodeWithMap( ListNode *headA, ListNode *headB ) {
    if ( !headA || !headB ) return nullptr;
    unordered_map<ListNode *, bool> map;
    for ( auto i = headA; i; i = i->next ) {
      map[i] = true;
    }
    for ( auto i = headB; i; i = i->next ) {
      if ( map.find( i ) != map.end() ) {
        return i;
      }
    }
    return nullptr;
  }

  ListNode *findFirstCommonNode( ListNode *headA, ListNode *headB ) {
    if ( !headA || !headB ) return nullptr;
    auto a = headA, b = headB;
    // Stop when a and b point to the same node
    // Note: nullptr == nullptr -> true
    while ( a != b ) {
      if ( !a ) {
        a = headB;
      } else {
        a = a->next;
      }

      if ( !b ) {
        b = headA;
      } else {
        b = b->next;
      }
    }
    return a;

    // Stop when a and b point to nullptr simultaneously
    // while ( a || b ) {
    //   if ( a == b ) {
    //     return a;
    //   }
    //   a = a->next;
    //   b = b->next;
    //   if ( !a && !b ) {
    //     return nullptr;
    //   }
    //   if ( !a ) {
    //     a = headB;
    //   }

    //   if ( !b ) {
    //     b = headA;
    //   }
    // }
    // return nullptr;
  }
};
