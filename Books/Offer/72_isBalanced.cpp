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
  bool res = true;
  bool isBalanced(TreeNode* root) {
    dfs(root);
    return res;
  }

  int dfs(TreeNode* t) {
    if (!t) return 0;

    int depth_l = dfs(t->left);
    int depth_r = dfs(t->right);
    if (abs(depth_l - depth_r) > 1) res = false;
    return max(depth_l, depth_r) + 1;
  }
};
