class Solution {
 public:
  ListNode *entryNodeOfLoop( ListNode *head ) {
    unordered_map<ListNode *, bool> map;
    int idx = 0;
    for ( auto i = head; i; i = i->next ) {
      if ( map.find( i ) == map.end() ) {
        map[i] = true;
      } else {
        return i;
      }
    }
    return nullptr;
  }
};
