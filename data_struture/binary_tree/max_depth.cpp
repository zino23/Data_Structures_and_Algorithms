#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *father;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), father(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r, TreeNode *f) : val(x), left(l), right(r), father(f) {}
};

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) { return 0; }

    queue<TreeNode *> q;
    int depth = 0;
    q.push(root);
    while (!q.empty()) {
      depth++;
      int len = q.size();
      while (len--) {
        auto node = q.front();
        q.pop();
        if (node->left != nullptr) { q.push(node->left); }
        if (node->right != nullptr) { q.push(node->right); }
      }
    }
    return depth;
  }

  int maxDepthRecur(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(maxDepthRecur(root->left), maxDepthRecur(root->right)) + 1;
  }

  int maxDepthV2(TreeNode *root) {
    if (root == nullptr) { return 0; }
    pair<TreeNode *, int> x{root, 1};
    queue<pair<TreeNode *, int>> q;
    vector<int> depth;

    q.push(x);

    while (!q.empty()) {
      auto s = q.front();
      q.pop();
      depth.push_back(s.second);

      auto node = s.first;
      if (node->left != nullptr) { q.push({node->left, s.second + 1}); }
      if (node->right != nullptr) { q.push({node->right, s.second + 1}); }
    }
    sort(depth.begin(), depth.end(), greater<int>());
    return depth[0];
  }
};
