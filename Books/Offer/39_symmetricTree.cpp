/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isSymEqual(TreeNode* a, TreeNode* b) {
    // Base case
    if (!a && !b) return true;
    if (!a && b || a && !b) return false;

    if (isSymEqual(a->left, b->right) && isSymEqual(a->right, b->left) &&
        a->val == b->val)
      return true;
    return false;
  }
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    if (isSymmetric(root->left, root->right)) {
      return true;
    }
    return false;
  }
};
