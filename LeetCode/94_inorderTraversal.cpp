/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    std::vector<int> res;
    // The stack will be empty in two cases:
    // 1. The actual root of the tree is popped
    // 2. All nodes have been traversed
    while (root || !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      // Hit the bottom, store top value
      root = stk.top();
      res.push_back(stk.top()->val);
      stk.pop();

      // Go to right
      // Note: if root is leaf, root->right will be nullptr, in the next
      // iteration, root's father, i.e. stk.top() will be fetched, and its value
      // will be stored, and then go to its right
      root = root->right;
    }
    return res;
  }

  vector<int> inorderTraversalRecur(TreeNode* root) {
    if (!root) return {};
    auto left = inorderTraversal(root->left);
    auto right = inorderTraversal(root->right);
    left.push_back(root->val);
    left.insert(left.end(), right.begin(), right.end());
    return left;
  }
};
