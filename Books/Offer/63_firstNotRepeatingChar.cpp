class Solution {
 public:
  char firstNotRepeatingChar(string s) {
    unordered_map<char, int> map;
    int i = 0;
    for (auto c : s) {
      if (map.find(c) == map.end()) {
        map[c] = 0;
      } else {
        map[c]++;
        while (i < s.size() && map[s[i]] > 0) { i++; }
      }
    }
    if (i < s.size()) {
      return s[i];
    } else {
      return '#';
    }
  }
};
