#include <vector>
using namespace std;

class Solution {
  bool veryfyPostorder(vector<int> postorder) {
    if (postorder.empty()) return true;
    return isPostorder(postorder, 0, postorder.size() - 1);
  }

  bool isPostorder(vector<int>& order, int l, int r) {
    // when current node has no left subtree, l > r
    if (l >= r) { return true; }

    int root_val = order[r];
    int i = l;
    // find the first node of right subtree
    while (i < r && order[i] < root_val) i++;
    // verify current layer correctness
    for (int j = i; j < r; j++) {
      if (order[j] < root_val) { return false; }
    }
    return isPostorder(order, l, i - 1) && isPostorder(order, i, r - 1);
  }
};
