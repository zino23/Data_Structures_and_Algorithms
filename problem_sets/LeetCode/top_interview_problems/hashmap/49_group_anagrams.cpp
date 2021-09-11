#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res(strs.size());
    /* Map string to its position in res */
    unordered_map<string, int> map;
    /* The next available position */
    int pos = 0;
    for (auto s : strs) {
      string tmp = s;
      /* Anagrams will be the same after sort */
      sort(tmp.begin(), tmp.end());
      /* New anagram */
      if (map.find(tmp) == map.end()) {
        map[tmp] = pos;
        res[pos++].push_back(s);
      } else {
        /* Existing anagram */
        res[map[tmp]].push_back(s);
      }
    }
    res.erase(res.begin() + pos, res.end());
    return res;
  }
};
