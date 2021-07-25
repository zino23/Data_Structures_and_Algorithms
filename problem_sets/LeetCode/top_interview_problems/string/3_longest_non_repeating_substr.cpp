#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    int l = 0, r = 0;
    unordered_map<char, bool> map;
    map[s[l]] = true;
    int res = 0;
    while (l < s.size()) {
      /* Move r until s[r] is in map or reach limits */
      while (r + 1 < s.size() && map.find(s[r + 1]) == map.end()) {
        map[s[r + 1]] = true;
        r++;
      }

      /* s[l, r] does not contain repeating chars */
      res = max(res, r - l + 1);

      /* Erase s[i] and inrement i */
      map.erase(s[l++]);
    }
    return res;
  }
};
