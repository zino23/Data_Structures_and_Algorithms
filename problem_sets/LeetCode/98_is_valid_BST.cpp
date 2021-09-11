#include <climits>
#include <iostream>
#include <stack>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> stk;
    long long last_val = static_cast<long long>(INT_MIN) - 1;
    while (!stk.empty() || root != nullptr) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      /**
       * root is nullptr due to 2 reasons
       * 1. root is bottom's left node
       * 2. root is bottom's right node
       */
      root = stk.top();
      stk.pop();
      if (root->val <= last_val) {
        return false;
      }

      /* Update last_val and go to the right node */
      last_val = root->val;
      root = root->right;
    }
    return true;
  }
};
