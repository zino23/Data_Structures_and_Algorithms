class Solution {
public:
  int longestSubstringWithoutDuplication(string s) {
    if (s.empty()) {
      return 0;
    }

    unordered_map<int, int> map;
    int res = -1;
    for (int i = 0; i < s.size(); i++) {
      map[s[i]] = 1;
      int j = i + 1;
      while (j < s.size() && map.find(s[j]) == map.end()) {
        map[s[j]] = 1;
        j++;
      }
      res = max(res, j - i);
      map.clear();
    }
    return res;
  }
};
