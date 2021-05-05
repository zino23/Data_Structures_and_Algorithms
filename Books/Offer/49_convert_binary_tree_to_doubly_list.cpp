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
  using PTT = pair<TreeNode*, TreeNode*>;

 public:
  PTT dfs( TreeNode* node ) {
    if ( !node ) return { nullptr, nullptr };
    PTT ans = { node, node };
    if ( node->left ) {
      auto pair = dfs( node->left );
      pair.second->right = node;
      node->left = pair.second;
      ans.first = pair.first;
    }
    if ( node->right ) {
      auto pair = dfs( node->right );
      pair.first->left = node;
      node->right = pair.first;
      ans.second = pair.second;
    }
    return ans;
  }

  TreeNode* convert( TreeNode* root ) {
    if ( !root ) return nullptr;
    auto cur = root;
    auto pair = dfs( root );
    return pair.first;
  }
};
