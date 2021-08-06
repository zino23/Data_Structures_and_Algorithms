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
  vector<int> rightSideView(TreeNode *root) {
    if (!root) {
      return {};
    }

    queue<TreeNode *> q;
    q.push(root);
    vector<int> res;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto t = q.front();
        q.pop();

        /* The most right node is at the end of the queue */
        if (size == 0) {
          res.push_back(t->val);
        }

        if (t->left) {
          q.push(t->left);
        }

        if (t->right) {
          q.push(t->right);
        }
      }
    }
    return res;
  }
};
