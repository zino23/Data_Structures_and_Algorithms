// Definition for singly-linked list.
#include <cstddef>
#include <iostream>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class Solution {
public:
  ListNode *quickSortList(ListNode *head) {
    if (!head)
      return nullptr;
    // 1. change value of each node
    vector<int> v;
    for (auto h = head; h != NULL; h = h->next) {
      v.push_back(h->val);
    }

    quickSort(v, 0, v.size() - 1);
    int i = 0;
    for (auto h = head; h != NULL; h = h->next) {
      h->val = v[i++];
    }
    return head;
  }

  void quickSort(vector<int> &v, int l, int r) {
    if (l >= r)
      return;
    int i = l - 1, j = r + 1;
    int mid = (i + j) >> 1;
    int pivot = v[mid];
    while (i < j) {
      do
        (i++);
      while (v[i] < pivot);
      do
        (j--);
      while (v[j] > pivot);
      // case 1: [.., i, .., j, ..]: v[i] >= pivot, v[j] <= pivot
      // case 1: [.., i/j, ..]: v[i] == v[j] == pivot
      // case 2: [.., j, i, ..]: v[i] > pivot > v[j]
      if (i < j)
        swap(v[i], v[j]);
    }
    quickSort(v, l, j);
    quickSort(v, j + 1, r);
  }
};

int main() {
  auto head = new ListNode(4);
  head->next = new ListNode(1);
  head->next->next = new ListNode(-4);
  auto s = new Solution;
  auto n = s->quickSortList(head);
  for (auto i = head; i; i = i->next) {
    cout << i->val << endl;
  }
  return 0;
}
