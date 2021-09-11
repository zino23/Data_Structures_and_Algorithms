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
  bool isSymmetric(TreeNode *root) {
    if (!root || !root->left && !root->right) {
      return true;
    }

    return isSym(root->left, root->right);
  }

  bool isSym(TreeNode *l, TreeNode *r) {
    if (l && !r || !l && r) {
      return false;
    }

    if (!l && !r) {
      return true;
    }

    return l->val == r->val && isSym(l->left, r->right) && isSym(l->right, r->left);
  }
};
