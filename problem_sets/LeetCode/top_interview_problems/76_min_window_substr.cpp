#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  using CharMap = unordered_map<char, int>;

 public:
  string minWindow(string s, string t) {
    CharMap ht, hs;
    for (auto c : t) {
      ht[c]++;
    }

    int cnt = 0;
    int num = t.size();
    pair<int, int> res{-1, -1};
    int len = INT_MAX;
    for (int l = 0, r = 0; r < s.size(); r++) {
      char c = s[r];
      hs[c]++;

      /**
       * This will set ht[c] to 0, if c is in s but not in t
       * Note: <=, not <
       */
      if (hs[c] <= ht[c]) {
        cnt++;
      }

      /**
       * Move l as right as possible
       * Note: ht[s[l]] is 0 when s[l] is not in t
       */
      while (hs[s[l]] > ht[s[l]]) {
        hs[s[l++]]--;
      }

      if (cnt == num) {
        int len_tmp = r - l + 1;
        if (len_tmp < len) {
          res = {l, len_tmp};
          len = len_tmp;
        }
      }
    }

    if (res.first != -1) {
      return s.substr(res.first, res.second);
    } else {
      return {};
    }
  }
};
