/* Definition for a binary tree node. */
#include <climits>
#include <iostream>

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
  int res = INT_MIN;

  /**
   * Calculate max path sum for each node @n, where @n is each path's top node
   */
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return res;
  }

  /* @return the max path sum from @node to a leaf */
  int dfs(TreeNode *node) {
    /* Base case */
    if (!node) {
      return 0;
    }

    int left = max(0, dfs(node->left));
    int right = max(0, dfs(node->right));
    res = max(res, left + node->val + right);
    return node->val + max(left, right);
  }
};
