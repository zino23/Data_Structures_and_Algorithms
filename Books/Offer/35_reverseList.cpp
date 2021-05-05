class Solution {
 public:
  ListNode* reverseList( ListNode* head ) {
    // Input is nullptr
    if ( !head ) {
      return nullptr;
    }
    // Base case
    if ( !head->next ) {
      return head;
    }
    auto new_head = reverseList( head->next );
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
};

