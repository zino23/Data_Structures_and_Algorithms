#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> res;

  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) return {};
    stack<TreeNode *> stk;
    vector<int> ans;
    stk.push(root);
    while (!stk.empty()) {
      auto node = stk.top();
      ans.push_back(node->val);
      stk.pop();
      if (node->left != nullptr) { stk.push(node->left); }
      if (node->right != nullptr) { stk.push(node->right); }
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }

  void postorderRecur(TreeNode *root) {
    if (root == nullptr) { return; }

    postorderRecur(root->left);
    postorderRecur(root->right);
    res.push_back(root->val);
  }
};
