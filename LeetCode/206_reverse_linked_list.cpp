#include <cstddef>
#include <iostream>

using namespace std;

class ListNode
{
	public:
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode ( int x ) : val(x), next(nullptr) {}
		ListNode ( int x, ListNode *next ) : val(x), next(next) {}
		ListNode* reverseListIter(ListNode* head);
		ListNode* reverseListRecur(ListNode* head);
};

ListNode* ListNode::reverseListIter(ListNode* head)
{
	if ( !head ) return head;

	// iteratively
	auto cur = head;
	ListNode *last = nullptr;
	while ( cur )
	{
		auto ori_next = cur->next;  // for iterating
		cur->next = last;  // reverse
		last = cur;  // save current node for reverse
		cur = ori_next;
	}
	return last;
}

ListNode* ListNode::reverseListRecur(ListNode *head)
{
	// base case
	if ( !head || !head->next ) return head;

	auto new_head = reverseListRecur(head->next);
	head->next->next = head;
	head->next = nullptr;
	return new_head;
}


int main()
{
	return 0;
}
