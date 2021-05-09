class Solution {
 public:
  vector<int> sequence;
  bool dfs(int l, int r) {
    if (l == r) return true;
    // The last node of BST is root
    int root = sequence[r];
    int k = l;
    while (k < r && sequence[k] < root) k++;
    while (k < r) {
      if (sequence[k] < root) { return false; }
      k++;
    }
    return dfs(l, k - 1) && dfs(k, r);
  }
  bool verifySequenceOfBST(vector<int> _sequence) {
    if (_sequence.empty()) return true;
    sequence = _sequence;
    if (dfs(0, sequence.size() - 1))
      return true;
    else
      return false;
  }
};
