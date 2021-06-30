class Solution {
public:
  vector<int> findNumbersWithSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    vector<int> res;
    for (auto i : nums) {
      if (map.find(target - i) != map.end()) {
        res.push_back(i);
        res.push_back(target - i);
        return res;
      }
      map[i] = 1;
    }
    return res;
  }
};
