#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    vector<ListNode*> nodes;
    for (auto i = head; i; i = i->next) { nodes.push_back(i); }
    vector<ListNode*> res(nodes.size());
    int i = 0, j = nodes.size() - 1;
    if (i == j) return;
    int k = 0;
    while (j > i) {
      res[k] = nodes[i];
      res[k + 1] = nodes[j];
      k = k + 2;
      i++;
      j--;
    }
    if (i == j) res[k] = nodes[i];
    for (int i = 0; i < res.size() - 1; i++) { res[i]->next = res[i + 1]; }
    res[res.size() - 1]->next = nullptr;
  }
};
