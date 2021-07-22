#include <queue>
#include <vector>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};

    queue<TreeNode *> q;
    vector<vector<int>> res;
    vector<int> level;

    q.push(root);
    while (!q.empty()) {
      // Size of nodes at the same level
      int size = q.size();
      level.clear();
      while (size--) {
        auto node = q.front();
        q.pop();
        // Add current level nodes's value
        level.push_back(node->val);
        // Add next level nodes
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      // Add current level's value into res
      res.push_back(level);
    }
    return res;
  }
};
