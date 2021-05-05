#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};

class Solution {
 public:
  vector<int> preorder, inorder;
  map<int, int> hash;

  TreeNode* buildTree( vector<int>& _preorder, vector<int>& _inorder ) {
    preorder = _preorder, inorder = _inorder;
    for ( int i = 0; i < inorder.size(); i++ ) {
      hash[inorder[i]] = i;
    }

    return dfs( 0, preorder.size() - 1, 0, inorder.size() - 1 );
  }

  TreeNode* dfs( int pl, int pr, int il, int ir ) {
    if ( pl > pr ) return nullptr;

    int k = hash[preorder[0]];
    TreeNode* root = new TreeNode( preorder[pl] );
    // the size of left subtree is k - il
    TreeNode* left = dfs( pl + 1, pl + k - il, il, k - 1 );
    TreeNode* right = dfs( pl + k - il + 1, pr, k + 1, ir );
    root->left = left, root->right = right;
    return root;
  }
};

int main() { return 0; }

