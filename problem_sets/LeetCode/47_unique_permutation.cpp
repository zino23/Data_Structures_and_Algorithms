#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  vector<int> cur;
  vector<bool> visited;
  vector<int> v;
  vector<vector<int>> permuteUnique(vector<int>& v_) {
    v = v_;
    visited = vector<bool>(v.size(), false);
    sort(v.begin(), v.end());
    dfs(0);
    return res;
  }

  void dfs(int pos) {
    if (pos == v.size()) {
      res.push_back(cur);
      return;
    }

    for (int i = 0; i < v.size(); i++) {
      if (visited[i] || i > 0 && v[i - 1] == v[i] && !visited[i - 1]) {
        continue;
      }

      visited[i] = true;
      cur.push_back(v[i]);
      dfs(pos + 1);
      cur.pop_back();
      visited[i] = false;
    }
  }
};
