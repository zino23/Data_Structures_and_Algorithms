#include <algorithm>
#include <iostream>
#include <vector
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i <= nums.size() - 3; i++) {
      int j = i + 1, k = nums.size() - 1;
      int target = -nums[i];
      while (j < k) {
        if (nums[j] + nums[k] < target) {
          j++;
        } else if (nums[j] + nums[k] > target) {
          k--;
        } else {
          res.push_back(vector<int>{nums[i], nums[j], nums[k]});
          while (j + 1 < nums.size() && nums[j + 1] == nums[j]) j++;
          while (k - 1 > i && nums[k - 1] == nums[k]) k--;
          j++;
          k--;
        }
      }
      // Move i to the end of repeating numbers
      while (i + 1 <= nums.size() - 3 && nums[i + 1] == nums[i]) i++;
    }
    return res;
  }
};
