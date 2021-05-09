#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
  vector<vector<int>> res;
  vector<int> level;
  vector<vector<int>> levelOrder(TreeNode *root) {
    bfs(root);
    return res;
  }

  void bfs(TreeNode *root) {
    queue<TreeNode *> q;
    if (root) q.push(root);
    while (!q.empty()) {
      vector<int> level;
      int size = q.size();
      while (size--) {
        auto t = q.front();
        q.pop();
        level.push_back(t->val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      res.push_back(level);
    }
  }
};
