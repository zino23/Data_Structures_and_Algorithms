class Solution {
 public:
  ListNode* merge( ListNode* l1, ListNode* l2 ) {
    // Just like merge sort
    ListNode* head = nullptr;
    auto cur = head;
    while ( l1 && l2 ) {
      if ( l1->val <= l2->val ) {
        if ( !head ) {
          head = l1;
          cur = head;
        } else {
          cur->next = l1;
          cur = l1;
        }
        l1 = l1->next;
      } else {
        if ( !head ) {
          head = l2;
          cur = head;
        } else {
          cur->next = l2;
          cur = l2;
        }
        l2 = l2->next;
      }
    }
    while ( l1 ) {
      // head is still nullptr
      if ( !head ) {
        head = l1;
        cur = head;
        l1 = l1->next;
        continue;
      }
      cur->next = l1;
      cur = l1;
      l1 = l1->next;
    }
    while ( l2 ) {
      if ( !head ) {
        head = l2;
        cur = head;
        l2 = l2->next;
        continue;
      }
      cur->next = l2;
      cur = l2;
      l2 = l2->next;
    }

    if ( head ) {
      cur->next = nullptr;
    }
    // l1 and l2 is all nullptr
    return head;
  }
};
