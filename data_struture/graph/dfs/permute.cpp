#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nums_;
  vector<vector<int>> res;
  unordered_map<int, bool> visited;
  vector<vector<int>> permute(vector<int>& nums) {
    nums_ = nums;
    for (auto i : nums) { visited[i] = false; }
    dfs(0, nums);
    return res;
  }

  void dfs(int x, vector<int>& nums) {
    if (x == nums_.size()) {
      res.push_back(nums_);
      return;
    }

    for (auto i : nums) {
      if (visited[i]) continue;
      visited[i] = true;
      nums_[x] = i;
      dfs(x + 1, nums);
      visited[i] = false;
    }
  }
};

int main() {
  Solution s;
  vector<int> a{1, 2, 3};
  s.permute(a);
  return 0;
}
