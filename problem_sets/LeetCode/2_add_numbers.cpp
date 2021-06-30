 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution
{
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto head = new ListNode(-1), cur = head;  // need to record the info of the head node
        int t = 0;
        while ( l1 || l2 || t )
        {
            if ( l1 != nullptr ) t += l1->val, l1 = l1->next;
            if ( l2 != nullptr ) t += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
        }
        return head->next;
    }
};