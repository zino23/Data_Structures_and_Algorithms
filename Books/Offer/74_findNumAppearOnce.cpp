class Solution {
public:
  int findNumberAppearingOnce(vector<int> &nums) {
    unordered_map<int, int> map;
    for (auto i : nums) {
      if (++map[i] == 3) {
        map.erase(i);
      }
    }
    return *(map.begin()).first;
  }
};
