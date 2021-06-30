class Solution {
 public:
  vector<int> findNumsAppearOnce(vector<int>& nums) {
    unordered_map<int, int> map;
    for (auto i : nums) {
      if (++map[i] == 2) { map.erase(i); }
    }
    vector<int> res;
    for (auto i : map) { res.push_back(i.first); }
    return res;
  }
};
