#include <climits>
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
  /* preorder sequenece of a BST monotically increases */
  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }

    long long prev = (long long)INT_MIN - 1;
    stack<TreeNode *> stk;
    while (!stk.empty() || root != nullptr) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();

      /**
       * In preorder sequenece, if find a value smaller or equal to its precessor, it is not a BST
       */
      if (root->val <= prev) {
        return false;
      }

      prev = root->val;
      root = root->right;
    }
    return true;
  }
};
