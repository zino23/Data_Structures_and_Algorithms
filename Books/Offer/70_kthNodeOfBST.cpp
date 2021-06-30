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
  int num = 0;
  vector<TreeNode *> inorder;
  int k;
  TreeNode *kthNode(TreeNode *root, int _k) {
    k = _k;
    inorder_traversal(root);
    return inorder[k - 1];
  }

  void inorder_traversal(TreeNode *t) {
    if (inorder.size() == k) {
      return;
    }

    if (!t) {
      return;
    }

    inorder_traversal(t->left);
    inorder.push_back(t);
    inorder_traversal(t->right);
  }
};
