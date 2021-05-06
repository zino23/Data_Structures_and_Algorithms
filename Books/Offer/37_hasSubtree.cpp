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
  vector<int> preorderTraversal(TreeNode* p) {
    if (!p) return {};
    auto left = preorderTraversal(p->left);
    auto right = preorderTraversal(p->right);
    vector<int> res{p->val};
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
  }

  bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (!pRoot2) return false;

    auto t1 = preorderTraversal(pRoot1);
    auto t2 = preorderTraversal(pRoot2);
    // Naive comparion
    for (int i = 0; i < t1.size(); i++) {
      if (t1[i] == t2[0]) {
        for (int j = 0; j < t2.size(); j++) {
          if (t1[i + j] != t2[j]) {
            break;
          }
          if (j == t2.size() - 1) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
