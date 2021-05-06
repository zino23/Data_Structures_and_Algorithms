/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode *next(TreeNode *p) {
    while (p->left) {
      p = p->left;
    }
    return p;
  }

  TreeNode *inorderSuccessor(TreeNode *p) {
    if (!p->right) {
      // Left subtree has been traversed, if right subtree does not exist
      while (p->father && p->father->left != p) {
        p = p->father;
      }
      return p->father;
    }

    // Right subtree exist
    return next(p->right);
  }
};
