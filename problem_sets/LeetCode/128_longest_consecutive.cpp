#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int res = 0;
    for (auto x : set) {
      if (set.count(x) > 0) {
        continue;
      }

      int cnt = 0;
      while (set.count(x) > 0) {
        cnt++;
        x++;
      }
      res = max(res, cnt);
    }
    return res;
  }
};
