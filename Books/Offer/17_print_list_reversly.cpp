#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
      stack<int> stk;
      for ( auto i = head; i != NULL; i = i->next ) {
        stk.push(i->val);
      }

      vector<int> res;
      int s = stk.size();
      for ( int i = 0; i < s; i++ ) {
        res.push_back(stk.top());
        stk.pop();
      }
      return res;
    }
};
