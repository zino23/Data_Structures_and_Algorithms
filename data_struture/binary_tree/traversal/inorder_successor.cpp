#include <stack>
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
  TreeNode *inorderSuccessor(TreeNode *p) {
    if (p->right != nullptr) {
      p = p->right;
      while (p->left != nullptr) { p = p->left; }
      return p;
    }

    while (p->father != nullptr && p->father->left != p) { p = p->father; }
    return p->father;
  }

  TreeNode *inorderSuccessorWithLargerVal(TreeNode *p) {
    auto next = inorderSuccessor(p);
    while (next != nullptr && next->val <= p->val) { next = inorderSuccessor(next); }
    return next;
  }

  TreeNode *inorderSuccessorWithLargerValNoParent(TreeNode *root, TreeNode *p) {
    stack<TreeNode *> stk;
    int comp = INT_MAX;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      if (root == p) { comp = p->val; }
      if (root->val > comp) { return root; }
      stk.pop();
      root = root->right;
    }
    return nullptr;
  }
};
