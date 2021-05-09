#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    unordered_map<int, int> map;
    int res = 0;
    for (int i = 0, j = 0; i < s.size(); i++) {
      // Index of each value
      map[s[i]] = i;
      for (j = i + 1; j < s.size() && map.find(s[j]) == map.end(); j++) {
        map[s[j]] = j;
      }
      res = max(res, j - i);
      map.clear();
      // s[i] == s[j], we don't need to do anything, just let i be incremented
      // in next loop
    }
    return res;
  }
};

int main() {
  string s;
  cin >> s;
  auto sol = new Solution();
  cout << sol->lengthOfLongestSubstring(s) << endl;
  return 0;
}
