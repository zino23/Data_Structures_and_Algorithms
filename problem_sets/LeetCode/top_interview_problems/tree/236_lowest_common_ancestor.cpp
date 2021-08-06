#include <cstddef>

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  /**
   * @return in a tree rooted at @root (@p and @q is exchangable)
   * 1. the lowest common ancestor of @p and @q if root->left has @p and
   * root->right has @q
   * 2. @p's lowest ancestor if @p in root->left and @q is not in root->right
   * 3. @q's lowest ancestor if @q in root->right and @p is not in root->left
   * 4. nullptr if @p is not in root->left and @q is not in root->right
   */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    if (root == p || root == q) {
      return root;
    }

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
      return root;
    }

    if (left && !right) {
      return left;
    }

    if (!left && right) {
      return right;
    }

    return nullptr;
  }
};
