#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int res = 0;
  vector<bool> visited;
  string s;

  void dfs(int idx) {
    if (idx == s.size()) {
      res++;
      return;
    }

    dfs(idx + 1);
    if (idx == s.size() - 1) return;
    int num = stoi(s.substr(idx, 2));
    if (num > 0 && num <= 25 && s[idx] != '0') dfs(idx + 2);
  }

  int getTranslationCount(string _s) {
    if (_s.empty()) return 0;
    s = _s;
    visited.resize(s.size(), false);
    dfs(0);
    return res;
  }
};
