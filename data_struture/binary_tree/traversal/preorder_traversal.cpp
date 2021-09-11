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

  /* For each node, print in the order: middle, left, right */
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> stk;
    vector<int> ans;

    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.push(root);
        ans.push_back(root->val);
        root = root->left;
      }

      // Hit bottom
      root = stk.top();
      stk.pop();
      root = root->right;
    }
    return ans;
  }

  vector<int> preorderTraversalV2(TreeNode *root) {
    if (!root) {
      return {};
    }

    stack<TreeNode *> stk;
    vector<int> res;
    stk.push(root);
    while (!stk.empty()) {
      auto t = stk.top();
      stk.pop();
      res.push_back(t->val);

      /* Push right subnode first  */
      if (t->right) {
        stk.push(t->right);
      }

      if (t->left) {
        stk.push(t->left);
      }
    }
    return res;
  }

  void preorderRecur(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    res.push_back(root->val);
    preorderRecur(root->left);
    preorderRecur(root->right);
  }
};

