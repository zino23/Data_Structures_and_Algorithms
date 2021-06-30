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
  int treeDepth(TreeNode* root) {
    // return dfs(root);
    return bfs(root);
  }

  int bfs(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      int size = q.size();
      depth++;
      while (size--) {
        auto t = q.front();
        q.pop();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      return depth;
    }
  }

  int dfs(TreeNode* t) {
    if (!t) return 0;

    return max(t->left, t->right) + 1;
  }
};
