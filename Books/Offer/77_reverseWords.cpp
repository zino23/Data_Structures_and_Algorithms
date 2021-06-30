class Solution {
public:
  string reverseWords(string s) {
    stack<string> stk;
    for (int i = 0; i < s.size(); i++) {
      int j = i;
      while (s[j] != ' ' && j < s.size()) {
        j++;
      }
      int size = j - i;
      stk.push(s.substr(i, size));
      i = j;
    }
    string res;
    while (!stk.empty()) {
      res = res + stk.top() + ' ';
      stk.pop();
    }
    return res.substr(0, res.size() - 1);
  }
};
