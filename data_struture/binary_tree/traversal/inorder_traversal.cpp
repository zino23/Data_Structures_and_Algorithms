#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Inorder traversal recursive method:
 * 1. call inorder(root->left) to traverse left subtree
 * 2. visit the root
 * 3. call inorder(root->right) to traverse right subtree

 * Non recursive method:
 * Use a stack to simulate the function frame
 */

class Solution {
 public:
  vector<int> res;
  vector<int> inorderTraversal(TreeNode *root) {
    // inorderRecur(root);
    if (root == nullptr) return {};
    vector<int> res;
    stack<TreeNode *> stk;

    /**
     * stk will be empty if
     * 1. the actural root is popped
     * 2. all nodes have been traversed
     */
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      /**
       * Case 1: hit bottom, root is bottom node's left node which is
       * nullptr, store the bottom node's value
       * Case 2: root is nullptr cos previous loop's root = root->right, go to
       * the next node (previous iteration's root's parent) and store its value
       */

      /* Note: do not define a local root with auto root = stk.top(); */
      root = stk.top();
      res.push_back(root->val);
      stk.pop();

      // Go to root's right subtree
      // Case 1: root->right != nullptr, keep exploring root->right's left
      // subtree Case 2: root->right == nullptr, go to next node according to
      // inorder
      root = root->right;
    }

    return res;
  }

  void inorderRecur(TreeNode *root) {
    if (root == nullptr) return;
    inorderRecur(root->left);
    res.push_back(root->val);
    inorderRecur(root->right);
  }
};
