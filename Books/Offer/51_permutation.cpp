#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  vector<bool> visited;
  void dfs(vector<int> &nums, int idx, int st) {
    if (idx == path.size()) {
      res.push_back(path);
      return;
    }

    if (idx == 0 || nums[idx] != nums[idx - 1])
      st = 0;

    // All positions nums[idx] can be put in
    for (int i = st; i < nums.size(); i++) {
      if (!visited[i]) {
        visited[i] = true;
        path[i] = nums[idx];
        dfs(nums, idx + 1, i + 1);
        path[i] = 0;
        visited[i] = false;
      }
    }
  }

  vector<vector<int>> permutation(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    path.resize(nums.size());
    visited.resize(nums.size(), false);
    dfs(nums, 0, 0);
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  auto s = new Solution();
  s->permutation(nums);
  return 0;
}
