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
  vector<vector<int>> res;
  vector<int> path;
  int sum = 0, cur_sum = 0;

  vector<vector<int>> findPath(TreeNode* root, int _sum) {
    if (!root) return {};

    sum = _sum;
    dfs(root);
    return res;
  }

  void dfs(TreeNode* t) {
    if (!t) { return; }

    path.push_back(t->val);
    cur_sum += t->val;

    if (!t->left && !t->right && cur_sum == sum) res.push_back(path);
    dfs(t->left);
    dfs(t->right);
    path.pop_back();
    cur_sum -= t->val;
  }
};

class Solution2 {
 public:
  vector<vector<int>> res;
  vector<int> path;
  int sum = 0, num = 0;
  void dfs(TreeNode* t) {
    if (num == sum && !t->left && !t->right) {
      res.push_back(path);
      return;
    }

    if (t->left) {
      num += t->left->val;
      path.push_back(t->left->val);
      dfs(t->left);
      num -= t->left->val;
      path.pop_back();
    }

    if (t->right) {
      num += t->right->val;
      path.push_back(t->right->val);
      dfs(t->right);
      num -= t->right->val;
      path.pop_back();
    }
  }
  vector<vector<int>> findPath(TreeNode* root, int _sum) {
    if (!root) return {};
    sum = _sum;
    num += root->val;
    path.push_back(root->val);
    dfs(root);
    return res;
  }
};
